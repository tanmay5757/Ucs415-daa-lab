
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Job {
    string id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void solveJobSequencing(vector<string>& ids, vector<int>& deadlines, vector<int>& profits, int n) {
    vector<Job> jobs(n);
    int maxDeadline = 0;

    for (int i = 0; i < n; i++) {
        jobs[i].id = ids[i];
        jobs[i].deadline = deadlines[i];
        jobs[i].profit = profits[i];
        if (deadlines[i] > maxDeadline) {
            maxDeadline = deadlines[i];
        }
    }

    sort(jobs.begin(), jobs.end(), compare);

    vector<string> result(maxDeadline + 1, "");
    vector<bool> slot(maxDeadline + 1, false);
    int totalProfit = 0;
    int jobCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = min(maxDeadline, jobs[i].deadline); j > 0; j--) {
            if (!slot[j]) {
                result[j] = jobs[i].id;
                slot[j] = true;
                totalProfit += jobs[i].profit;
                jobCount++;
                break;
            }
        }
    }

    cout << "Selected Jobs: [";
    bool first = true;
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i]) {
            if (!first) cout << ", ";
            cout << result[i];
            first = false;
        }
    }
    cout << "]" << endl;
    cout << "Maximum Profit = " << totalProfit << endl;
}

int main() {
    int N = 5;
    vector<string> jobs = {"J1", "J2", "J3", "J4", "J5"};
    vector<int> deadlines = {2, 1, 2, 1, 3};
    vector<int> profits = {100, 19, 27, 25, 15};

    solveJobSequencing(jobs, deadlines, profits, N);

    return 0;
}
