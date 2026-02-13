#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array is empty!" << endl;
        return 0;
    }

    int arr[n];

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    auto start = high_resolution_clock::now();

    int min = arr[0];
    int max = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] < min)
            min = arr[i];
        if(arr[i] > max)
            max = arr[i];
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "\nMinimum element: " << min << endl;
    cout << "Maximum element: " << max << endl;

    cout << "Execution time: " << duration.count() << " nanoseconds" << endl;

    long long storage = sizeof(arr) + sizeof(min) + sizeof(max) + sizeof(n);
    cout << "Storage used: " << storage << " bytes" << endl;

    return 0;
}