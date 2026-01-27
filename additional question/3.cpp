#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int x;
    cin >> x;
    int mn = x, mx = x;

    for (int i = 1; i < N; i++) {
        cin >> x;
        mn = min(mn, x);
        mx = max(mx, x);
    }

    cout << mn + mx;
    return 0;
}
