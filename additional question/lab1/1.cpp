#include <iostream>
#include <vector>
using namespace std;

int binarySearchRecursive(const vector<int>& arr, int low, int high, int target) {
    if (high < low)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
        return mid;

    if (arr[mid] > target)
        return binarySearchRecursive(arr, low, mid - 1, target);

    return binarySearchRecursive(arr, mid + 1, high, target);
}

int main() {
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 23;
    int n = arr.size();

    int result = binarySearchRecursive(arr, 0, n - 1, target);

    if (result != -1)
        cout << "Target " << target << " found at index: " << result << endl;
    else
        cout << "Target not found in the array." << endl;

    return 0;
}