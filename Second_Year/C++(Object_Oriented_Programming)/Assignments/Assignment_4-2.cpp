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
protected:
    int accNo;
    long balance;
    Customer customer;
public:
    Account(int acc, long bal, Customer c) : accNo(acc), balance(bal), customer(c) {}
    virtual void calculateInterest() = 0;
    virtual void deposit(long amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid amount!" << endl;
        }
    }
    virtual void withdraw(long amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }
    virtual void display() {
        customer.show();
        cout << "Account No: " << accNo << " | Balance: " << balance << endl;
    }
    virtual ~Account() {}
};

class Savings : public Account {
public:
    Savings(int acc, long bal, Customer c) : Account(acc, bal, c) {}
    void calculateInterest() override {
        long interest = balance * 0.05;
        balance += interest;
        cout << "5% Interest added: " << interest << endl;
    }
};

class Checking : public Account {
public:
    Checking(int acc, long bal, Customer c) : Account(acc, bal, c) {}
    void calculateInterest() override {
        balance -= 10;
        cout << "Maintenance fee deducted: 10" << endl;
    }
};

int main() {
    string name;
    int id, acc;
    long bal;
    int accType;

    cout << "Enter name, ID, account number, balance: ";
    cin >> name >> id >> acc >> bal;
    cout << "Select Account Type (1. Savings  2. Checking): ";
    cin >> accType;

    Customer c(name, id);
    Account* account;

    if (accType == 1)
        account = new Savings(acc, bal, c);
    else
        account = new Checking(acc, bal, c);

    int choice;
    long amt;

    do {
        cout << "\n--- Banking Menu ---\n";
        cout << "1. Display Account Info\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Apply Interest / Charges\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                account->display();
                break;
            case 2:
                cout << "Enter deposit amount: ";
                cin >> amt;
                account->deposit(amt);
                break;
            case 3:
                cout << "Enter withdrawal amount: ";
                cin >> amt;
                account->withdraw(amt);
                break;
            case 4:
                account->calculateInterest();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    delete account;
    return 0;
}
