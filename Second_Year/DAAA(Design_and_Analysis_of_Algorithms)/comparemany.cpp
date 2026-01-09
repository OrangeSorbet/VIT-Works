#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void minmax(const vector<int>& nos) {
    if (nos.empty()) cout << "No numbers entered" << endl;

    int minVal = nos[0];
    int maxVal = nos[0];

    for (size_t i = 1; i < nos.size(); i++) {
        if (nos[i] < minVal) minVal = nos[i];
        if (nos[i] > maxVal) maxVal = nos[i];
    }

    cout << "Min: " << minVal << ", Max: " << maxVal << endl;
}

int main() {
    vector<int> nos;
    int input;

    cout << "Enter integers (enter any non-number like 'q' to finish):" << endl;

    while (cin >> input) {
        nos.push_back(input);
    }

    if (!cin.eof()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    minmax(nos);
    return 0;
}