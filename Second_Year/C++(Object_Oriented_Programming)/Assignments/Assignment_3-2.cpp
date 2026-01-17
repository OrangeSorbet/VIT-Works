#include <iostream>
using namespace std;

class Customer {
    string name;
    int id;
public:
    Customer(string n, int i) : name(n), id(i) {}
    void show() { cout << "Customer: " << name << " | ID: " << id << endl; }
};

class Account {
    int accNo;
    long balance;
    Customer customer;
public:
    Account(int acc, long bal, Customer c) : accNo(acc), balance(bal), customer(c) {}
    void deposit(long amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid amount!" << endl;
        }
    }
    void withdraw(long amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }
    void display() {
        customer.show();
        cout << "Account No: " << accNo << " | Balance: " << balance << endl;
    }
};

int main() {
    string name;
    int id, acc;
    long bal;

    cout << "Enter name, ID, account number, balance: ";
    cin >> name >> id >> acc >> bal;

    Customer c(name, id);
    Account a(acc, bal, c);

    int choice;
    long amt;

    do {
        cout << "\n--- Banking Menu ---\n";
        cout << "1. Display Account Info\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                a.display();
                break;
            case 2:
                cout << "Enter deposit amount: ";
                cin >> amt;
                a.deposit(amt);
                break;
            case 3:
                cout << "Enter withdrawal amount: ";
                cin >> amt;
                a.withdraw(amt);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
