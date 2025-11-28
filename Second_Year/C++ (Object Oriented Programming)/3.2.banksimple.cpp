#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Customer {
private:
    string name;
    string id;
public:
    Customer(string cname, string cid) {
        name = cname;
        id = cid;
    }

    string getName() {
        return name;
    }

    string getID() {
        return id;
    }
};

class Account {
private:
    Customer customer;
    double balance;
public:
    Account(Customer c) : customer(c), balance(0.0) {}

    void showDetails() {
        cout << "\n-----------------------------\n";
        cout << "     Customer Information\n";
        cout << "-----------------------------\n";
        cout << "Name      : " << customer.getName() << endl;
        cout << "ID        : " << customer.getID() << endl;
        cout << fixed << setprecision(2);
        cout << "Balance   : $" << balance << endl;
        cout << "-----------------------------\n";
    }

    void deposit() {
        double amount;
        cout << "\nEnter amount to deposit: $";
        while (!(cin >> amount) || amount <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid amount. Enter a positive value: $";
        }
        balance += amount;
        cout << "Deposited successfully. New Balance: $" << balance << endl;
    }

    void withdraw() {
        double amount;
        cout << "\nEnter amount to withdraw: $";
        while (!(cin >> amount) || amount <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid amount. Enter a positive value: $";
        }
        if (amount > balance) {
            cout << "Insufficient funds. Current Balance: $" << balance << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful. New Balance: $" << balance << endl;
        }
    }
};

int main() {
    string name, id;
    cout << "Welcome to Simple Bank\n";
    cout << "Enter customer name: ";
    getline(cin, name);
    cout << "Enter customer ID: ";
    getline(cin, id);

    Customer customer(name, id);
    Account account(customer);

    int choice;
    do {
        cout << "\n----------- MENU -----------\n";
        cout << "1. View Account Details\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        while (!(cin >> choice) || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice. Enter 1-4: ";
        }

        switch (choice) {
            case 1:
                account.showDetails();
                break;
            case 2:
                account.deposit();
                break;
            case 3:
                account.withdraw();
                break;
            case 4:
                cout << "\nThank you for using Simple Bank!\n";
                break;
        }
    } while (choice != 4);
}