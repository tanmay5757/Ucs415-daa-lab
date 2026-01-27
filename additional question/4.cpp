#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    long long specialty = 0;

    for (int i = 0; i < n; i++) {
        int cnt = 0;

        // left side
        for (int j = 0; j < i; j++)
            if (A[j] > A[i]) cnt++;

        // right side
        for (int j = i + 1; j < n; j++)
            if (A[j] > A[i]) cnt++;

        if (cnt >= k)
            specialty += A[i];
    }

    cout << specialty;
    return 0;
}
