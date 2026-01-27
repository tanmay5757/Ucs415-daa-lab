#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end());

    int left = 0, ans = 1;

    for (int right = 0; right < N; right++) {
        while (A[right] - A[left] > 10)
            left++;

        ans = max(ans, right - left + 1);
    }

    cout << ans;
}
