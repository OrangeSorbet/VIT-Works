#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<int> nums;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the numbers:" << endl;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }
    double mean = sum / n;

    sort(nums.begin(), nums.end());

    double median;
    if (n % 2 == 0)
        median = (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
    else
        median = nums[n / 2];

    int mode = nums[0];
    int maxCount = 1;

    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j])
                count++;
        }
        if (count > maxCount) {
            maxCount = count;
            mode = nums[i];
        }
    }

    cout << "Mean: " << mean << endl;
    cout << "Median: " << median << endl;
    cout << "Mode: " << mode << endl;
}