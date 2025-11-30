#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Entry {
    int key;
    int value;
    bool occupied;
    bool deleted;
    Entry() : key(0), value(0), occupied(false), deleted(false) {}
};

class HashMap {
private:
    Entry* table;
    int tableSize;

public:
    HashMap(int size) {
        tableSize = size;
        table = new Entry[tableSize];
    }

    ~HashMap() {
        delete[] table;
    }


    int hashFunction(int key) const {
        int h = key % tableSize;
        if (h < 0) h += tableSize;
        return h;
    }

    string insertKey(int key, int value) {
        int idx = hashFunction(key);
        int firstTomb = -1;
        int count = 0;

        while (count < tableSize) {
            Entry &e = table[idx];

            if (e.occupied && !e.deleted && e.key == key) {
                return "Key already exists. Use update to change value.";
            }

            if (!e.occupied && e.deleted && firstTomb == -1) {
                firstTomb = idx;
            }

            if (!e.occupied && !e.deleted) {
                int useIdx = (firstTomb != -1) ? firstTomb : idx;
                table[useIdx].key = key;
                table[useIdx].value = value;
                table[useIdx].occupied = true;
                table[useIdx].deleted = false;
                return "Inserted successfully.";
            }

            idx = (idx + 1) % tableSize;
            count++;
        }

        if (firstTomb != -1) {
            table[firstTomb].key = key;
            table[firstTomb].value = value;
            table[firstTomb].occupied = true;
            table[firstTomb].deleted = false;
            return "Inserted successfully (reused deleted slot).";
        }

        return "Hash table is full.";
    }

    bool searchKey(int key, int &outValue) const {
        int idx = hashFunction(key);
        int count = 0;

        while (count < tableSize) {
            const Entry &e = table[idx];

            if (e.occupied && !e.deleted && e.key == key) {
                outValue = e.value;
                return true;
            }

            if (!e.occupied && !e.deleted) {
                return false;
            }

            idx = (idx + 1) % tableSize;
            count++;
        }
        return false;
    }

    string updateKey(int key, int newValue) {
        int idx = hashFunction(key);
        int count = 0;

        while (count < tableSize) {
            Entry &e = table[idx];

            if (e.occupied && !e.deleted && e.key == key) {
                e.value = newValue;
                return "Value updated successfully.";
            }

            if (!e.occupied && !e.deleted)
                return "Key not found.";

            idx = (idx + 1) % tableSize;
            count++;
        }

        return "Key not found.";
    }

    string deleteKey(int key) {
        int idx = hashFunction(key);
        int count = 0;

        while (count < tableSize) {
            Entry &e = table[idx];

            if (e.occupied && !e.deleted && e.key == key) {
                e.occupied = false;
                e.deleted = true;
                e.key = 0;
                e.value = 0;
                return "Deleted successfully.";
            }

            if (!e.occupied && !e.deleted)
                return "Key not found.";

            idx = (idx + 1) % tableSize;
            count++;
        }

        return "Key not found.";
    }

    void display() const {
        cout << "\nCurrent Hash Table:\n";
        for (int i = 0; i < tableSize; ++i) {
            const Entry &e = table[i];
            cout << "[" << i << "] ";
            if (e.occupied && !e.deleted) {
                cout << "(" << e.key << " -> " << e.value << ")";
            } else if (!e.occupied && e.deleted) {
                cout << "DELETED";
            } else {
                cout << "EMPTY";
            }
            cout << "\n";
        }
        cout << endl;
    }
};

bool parseIntStrict(const string &input, int &out) {
    stringstream ss(input);
    char c;
    if (!(ss >> out)) return false;
    if (ss >> c) return false;
    return true;
}

int readInt(const string &prompt) {
    string line;
    int value;
    bool valid = false;

    while (!valid) {
        cout << prompt;
        getline(cin, line);
        valid = parseIntStrict(line, value);
        if (!valid) cout << "Invalid input. Please enter an integer.\n";
    }
    return value;
}

int main() {
    cout << "Hash Map\n";

    int size = -1;
    while (size <= 0) {
        size = readInt("Enter hash table size: ");
        if (size <= 0) {
            cout << "Enter a +ve int.\n";
        }
    }

    HashMap hm(size);
    bool exitProgram = false;

    while (!exitProgram) {
        cout << "\n-----=MENU------\n";
        cout << "1  Insert\n";
        cout << "2  Search\n";
        cout << "3  Update\n";
        cout << "4  Delete\n";
        cout << "5  Display Table\n";
        cout << "6  Exit\n";
        cout << "-----------------\n";

        int choice = readInt("Choose an option: ");
        int key, value;
        string message;

        if (choice == 1) {
            key = readInt("Enter key to insert: ");
            value = readInt("Enter value for key: ");
            message = hm.insertKey(key, value);
            cout << message << endl;
        }
        else if (choice == 2) {
            key = readInt("Enter key to search: ");
            int foundValue;
            bool found = hm.searchKey(key, foundValue);
            if (found) cout << "Key found, value = " << foundValue << endl;
            else cout << "Key not found." << endl;
        }
        else if (choice == 3) {
            key = readInt("Enter key to update: ");
            value = readInt("Enter new value: ");
            message = hm.updateKey(key, value);
            cout << message << endl;
        }
        else if (choice == 4) {
            key = readInt("Enter key to delete: ");
            message = hm.deleteKey(key);
            cout << message << endl;
        }
        else if (choice == 5) {
            hm.display();
        }
        else if (choice == 6) {
            exitProgram = true;
            cout << "Exiting program. Goodbye!\n";
        }
        else {
            cout << "Invalid choice. Please choose between 1-6.\n";
        }
    }
    return 0;
}
