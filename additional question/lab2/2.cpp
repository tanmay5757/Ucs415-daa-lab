#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int timeToMinutes(string t) {
    int h = stoi(t.substr(0, 2));
    int m = stoi(t.substr(3, 2));
    return h * 60 + m;
}

void findMinPlatforms(vector<string>& at_str, vector<string>& dt_str) {
    int n = at_str.size();
    vector<int> arr(n), dep(n);

    for (int i = 0; i < n; i++) {
        arr[i] = timeToMinutes(at_str[i]);
        dep[i] = timeToMinutes(dt_str[i]);
    }

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int platforms_needed = 1;
    int result = 1;
    int i = 1; 
    int j = 0; 

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms_needed++;
            i++;
        }
        else {
            platforms_needed--;
            j++;
        }

        if (platforms_needed > result)
            result = platforms_needed;
    }

    cout << "Minimum number of platforms required = " << result << endl;
}

int main() {
    vector<string> AT = {"09:00", "09:10", "09:20", "11:00", "11:20"};
    vector<string> DT = {"09:40", "12:00", "09:50", "11:30", "11:40"};

    findMinPlatforms(AT, DT);

    return 0;
}