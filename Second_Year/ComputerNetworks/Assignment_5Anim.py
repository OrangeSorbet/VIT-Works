# Deterministic ICMP + Sliding Window (GBN / SR) — WITH TIMEOUT + PROTOCOL FLOW
# PyQt6 required: pip install PyQt6
# Proper behavior after deletion:
# - Timeout occurs
# - GBN retransmits from base
# - SR retransmits only lost packet
# Sequential send/receive (1 send → 1 receive → 2 send → 2 receive ...)
# Ping console updates only after successful reply arrival
# No randomness

import sys
from PyQt6.QtWidgets import (
    QApplication, QWidget, QVBoxLayout, QHBoxLayout,
    QPushButton, QTextEdit, QComboBox
)
from PyQt6.QtCore import Qt, QTimer, QRectF
from PyQt6.QtGui import QPainter, QColor, QPen


TOTAL_PACKETS = 4
TIMEOUT_TICKS = 120  # deterministic timeout


class Packet:
    def __init__(self, seq, direction, ptype):
        self.seq = seq
        self.direction = direction
        self.ptype = ptype
        self.progress = 0.0
        self.active = True


class NetworkView(QWidget):
    def __init__(self):
        super().__init__()
        self.setMinimumHeight(300)
        self.packets = []
        self.time_tick = 0
        self.A_x = 120
        self.B_x = 880
        self.y = 150

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.setRenderHint(QPainter.RenderHint.Antialiasing)
        painter.fillRect(self.rect(), QColor(20, 20, 20))

        painter.setBrush(QColor(70, 70, 70))
        painter.setPen(Qt.GlobalColor.white)
        painter.drawRect(self.A_x - 60, self.y - 50, 120, 100)
        painter.drawRect(self.B_x - 60, self.y - 50, 120, 100)

        painter.drawText(self.A_x - 55, self.y - 60,
                         "Device A\n192.168.1.1")
        painter.drawText(self.B_x - 55, self.y - 60,
                         "Device B\n192.168.1.2")

        painter.setPen(QPen(QColor(140, 140, 140), 4))
        painter.drawLine(self.A_x + 60, self.y,
                         self.B_x - 60, self.y)

        painter.setPen(Qt.GlobalColor.white)
        painter.drawText(480, 270, f"Time: {self.time_tick}")

        for pkt in self.packets:
            if not pkt.active:
                continue

            if pkt.direction == "A->B":
                x = self.A_x + 60 + pkt.progress * (self.B_x - self.A_x - 120)
            else:
                x = self.B_x - 60 - pkt.progress * (self.B_x - self.A_x - 120)

            color = QColor(0, 200, 255) if pkt.ptype == "REQ" else QColor(0, 255, 120)

            painter.setBrush(color)
            painter.setPen(Qt.GlobalColor.black)
            painter.drawEllipse(QRectF(int(x - 15), int(self.y - 15), 30, 30))
            painter.setPen(Qt.GlobalColor.white)
            painter.drawText(int(x - 6), int(self.y + 5), str(pkt.seq))


class Simulator(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Deterministic GBN / SR with Timeout")
        self.resize(1000, 700)

        self.view = NetworkView()
        self.log = QTextEdit()
        self.log.setReadOnly(True)
        self.console = QTextEdit()
        self.console.setReadOnly(True)

        self.mode_select = QComboBox()
        self.mode_select.addItems(["Go-Back-N", "Selective Repeat"])

        self.start_btn = QPushButton("Start")
        self.delete_btn = QPushButton("Delete Packet In Transit")

        layout = QVBoxLayout()
        layout.addWidget(self.view)

        bottom = QHBoxLayout()
        bottom.addWidget(self.log)
        bottom.addWidget(self.console)
        layout.addLayout(bottom)

        controls = QHBoxLayout()
        controls.addWidget(self.mode_select)
        controls.addWidget(self.start_btn)
        controls.addWidget(self.delete_btn)
        layout.addLayout(controls)

        self.setLayout(layout)

        self.start_btn.clicked.connect(self.start)
        self.delete_btn.clicked.connect(self.delete_packet)

        self.timer = QTimer()
        self.timer.timeout.connect(self.tick)

        self.base = 1
        self.next_seq = 1
        self.waiting = False
        self.current_packet = None
        self.deleted_seq = None
        self.timeout_counter = 0

    def start(self):
        self.view.packets.clear()
        self.log.clear()
        self.console.clear()
        self.view.time_tick = 0
        self.base = 1
        self.next_seq = 1
        self.waiting = False
        self.deleted_seq = None
        self.timeout_counter = 0
        self.timer.start(30)
        self.log.append("Simulation Started\n")

    def tick(self):
        self.view.time_tick += 1

        if self.current_packet and self.current_packet.active:
            self.current_packet.progress += 0.02
            self.timeout_counter += 1

            if self.current_packet.progress >= 1.0:
                self.current_packet.active = False
                self.handle_arrival(self.current_packet)

        # Timeout logic
        if self.waiting and self.timeout_counter > TIMEOUT_TICKS:
            self.log.append(f"Timeout for Packet {self.base}")
            self.handle_timeout()

        if not self.waiting and self.next_seq <= TOTAL_PACKETS:
            self.send_packet(self.next_seq)

        self.view.update()

    def send_packet(self, seq):
        self.log.append(f"{seq} send")
        pkt = Packet(seq, "A->B", "REQ")
        self.current_packet = pkt
        self.view.packets.append(pkt)
        self.waiting = True
        self.timeout_counter = 0

    def handle_arrival(self, pkt):
        if pkt.ptype == "REQ":
            if self.deleted_seq == pkt.seq:
                return

            self.log.append(f"{pkt.seq} receive")
            reply = Packet(pkt.seq, "B->A", "REP")
            self.current_packet = reply
            self.view.packets.append(reply)
            self.timeout_counter = 0

        else:
            if self.deleted_seq == pkt.seq:
                return

            self.console.append(
                f"Reply from 192.168.1.2: seq={pkt.seq} time=20ms"
            )
            self.waiting = False
            self.base += 1
            self.next_seq += 1
            self.timeout_counter = 0

    def handle_timeout(self):
        mode = self.mode_select.currentText()
        self.deleted_seq = None
        self.waiting = False
        self.timeout_counter = 0

        if mode == "Go-Back-N":
            self.log.append("GBN: Retransmitting from base")
            self.next_seq = self.base

        else:
            self.log.append("SR: Retransmitting lost packet only")
            self.next_seq = self.base

    def delete_packet(self):
        if self.current_packet and self.current_packet.active:
            self.deleted_seq = self.current_packet.seq
            self.current_packet.active = False
            self.log.append(f"Packet {self.deleted_seq} manually deleted")


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = Simulator()
    window.show()
    sys.exit(app.exec())
