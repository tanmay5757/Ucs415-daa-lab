#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxSubArraySum(const vector<int> &arr)
{
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        max_ending_here += arr[i];

        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int main()
{
    vector<int> arr = {-2, -5, 6, -2, -3, 1, 5, -6};

    cout << "Maximum subarray sum is " << maxSubArraySum(arr) << endl;

    return 0;
}