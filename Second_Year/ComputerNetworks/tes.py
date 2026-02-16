import sys
from PyQt6.QtWidgets import (
    QApplication, QWidget, QVBoxLayout, QHBoxLayout,
    QPushButton, QTextEdit, QComboBox, QLabel, QSpinBox
)
from PyQt6.QtCore import Qt, QTimer
from PyQt6.QtGui import QPainter, QColor, QPen


TOTAL = 4
WINDOW = 4
TIMEOUT = 800
SEND_SCHEDULE = {1: 100, 2: 200, 3: 300, 4: 400}


class Packet:
    def __init__(self, seq, direction, ack=False):
        self.seq = seq
        self.direction = direction
        self.progress = 0.0
        self.active = True
        self.ack = ack


class NetworkView(QWidget):
    def __init__(self):
        super().__init__()
        self.setMinimumHeight(350)
        self.packets = []
        self.time = 0

        self.sender_x = 120
        self.receiver_x = 880
        self.y = 150

        self.window_base = 1
        self.receiver_expected = 1
        self.receiver_buffer = set()

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.fillRect(self.rect(), QColor(25, 25, 25))

        painter.setPen(Qt.GlobalColor.white)
        painter.drawText(20, 20, f"Sender Base: {self.window_base}")
        painter.drawText(20, 40, f"Receiver Expected: {self.receiver_expected}")
        painter.drawText(750, 40, f"Buffer: {sorted(self.receiver_buffer)}")
        painter.drawText(430, 320, f"Time: {self.time} ms")

        painter.setBrush(QColor(70, 70, 70))
        painter.drawRect(self.sender_x - 60, self.y - 50, 120, 100)
        painter.drawRect(self.receiver_x - 60, self.y - 50, 120, 100)

        painter.drawText(self.sender_x - 35, self.y - 60, "Sender")
        painter.drawText(self.receiver_x - 40, self.y - 60, "Receiver")

        painter.setPen(QPen(QColor(150, 150, 150), 3))
        painter.drawLine(self.sender_x + 60, self.y,
                         self.receiver_x - 60, self.y)

        for pkt in self.packets:
            if not pkt.active:
                continue

            if pkt.direction == "A->B":
                x = self.sender_x + 60 + pkt.progress * (self.receiver_x - self.sender_x - 120)
            else:
                x = self.receiver_x - 60 - pkt.progress * (self.receiver_x - self.sender_x - 120)

            color = QColor(0, 255, 0) if pkt.ack else QColor(0, 200, 255)
            painter.setBrush(color)
            painter.drawEllipse(int(x - 12), self.y - 12, 24, 24)
            painter.drawText(int(x - 5), self.y + 5, str(pkt.seq))


class Simulator(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Sliding Window Clean Architecture")
        self.resize(1100, 750)

        self.view = NetworkView()
        self.log = QTextEdit()
        self.log.setReadOnly(True)

        self.mode = QComboBox()
        self.mode.addItems(["Go-Back-N", "Selective Repeat"])

        self.start_btn = QPushButton("Start")

        self.speed_box = QSpinBox()
        self.speed_box.setRange(1, 50)
        self.speed_box.setValue(10)

        self.delete_buttons = {}
        delete_layout = QHBoxLayout()
        for i in range(1, 5):
            btn = QPushButton(f"Delete {i}")
            btn.setEnabled(False)
            btn.clicked.connect(lambda _, s=i: self.delete_packet(s))
            self.delete_buttons[i] = btn
            delete_layout.addWidget(btn)

        layout = QVBoxLayout()
        layout.addWidget(self.view)
        layout.addWidget(self.log)

        controls = QHBoxLayout()
        controls.addWidget(self.mode)
        controls.addWidget(self.start_btn)
        controls.addWidget(QLabel("Speed"))
        controls.addWidget(self.speed_box)

        layout.addLayout(controls)
        layout.addLayout(delete_layout)
        self.setLayout(layout)

        self.start_btn.clicked.connect(self.start)

        self.timer = QTimer()
        self.timer.timeout.connect(self.tick)

    def start(self):
        self.view.packets.clear()
        self.view.time = 0

        self.sender_base = 1
        self.receiver_expected = 1
        self.receiver_buffer = set()

        self.acked = set()
        self.send_time = {}
        self.deleted = set()
        self.done = False

        self.log.clear()
        self.packet_speed = self.speed_box.value() / 1000
        self.timer.start(10)

    def tick(self):
        self.view.time += 10
        self.view.window_base = self.sender_base
        self.view.receiver_expected = self.receiver_expected
        self.view.receiver_buffer = self.receiver_buffer

        for seq, t in SEND_SCHEDULE.items():
            if self.view.time == t:
                self.send(seq)

        for pkt in self.view.packets:
            if not pkt.active:
                continue
            pkt.progress += self.packet_speed
            if pkt.progress >= 1:
                pkt.active = False
                if pkt.ack:
                    self.handle_ack(pkt.seq)
                else:
                    self.receive(pkt.seq)

        self.check_timeouts()
        self.view.update()

    def send(self, seq):
        self.log.append(f"{self.view.time}ms → Send {seq}")
        self.send_time[seq] = self.view.time
        self.view.packets.append(Packet(seq, "A->B"))
        self.delete_buttons[seq].setEnabled(True)

    def receive(self, seq):
        self.delete_buttons[seq].setEnabled(False)

        if seq in self.deleted:
            self.log.append(f"{seq} lost")
            return

        if self.mode.currentText() == "Go-Back-N":
            if seq == self.receiver_expected:
                self.receiver_expected += 1
                self.send_ack(seq)
            else:
                if seq > self.receiver_expected:
                    self.log.append(f"{seq} discarded (out of order)")
        else:
            if seq >= self.receiver_expected:
                self.receiver_buffer.add(seq)
                self.send_ack(seq)

                while self.receiver_expected in self.receiver_buffer:
                    self.receiver_buffer.remove(self.receiver_expected)
                    self.receiver_expected += 1

    def send_ack(self, seq):
        self.view.packets.append(Packet(seq, "B->A", ack=True))

    def handle_ack(self, seq):
        if seq < self.sender_base:
            return

        self.log.append(f"ACK {seq}")
        self.acked.add(seq)

        if self.mode.currentText() == "Go-Back-N":
            while self.sender_base in self.acked:
                self.sender_base += 1
        else:
            while self.sender_base in self.acked:
                self.sender_base += 1

        if self.sender_base > TOTAL and not self.done:
            self.done = True
            rtt = self.view.time - SEND_SCHEDULE[1]
            self.log.append(f"\nReply from 192.168.1.2: time = {rtt} ms")

    def check_timeouts(self):
        if self.done:
            return

        for seq in range(self.sender_base, TOTAL + 1):
            if seq not in self.acked and seq in self.send_time:
                if self.view.time - self.send_time[seq] >= TIMEOUT:
                    self.log.append(f"Timeout on {seq}")
                    if self.mode.currentText() == "Go-Back-N":
                        for s in range(self.sender_base, TOTAL + 1):
                            if s not in self.acked:
                                self.send(s)
                    else:
                        self.send(seq)
                    break

    def delete_packet(self, seq):
        self.deleted.add(seq)
        self.delete_buttons[seq].setEnabled(False)
        self.log.append(f"Packet {seq} manually deleted")


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = Simulator()
    window.show()
    sys.exit(app.exec())
