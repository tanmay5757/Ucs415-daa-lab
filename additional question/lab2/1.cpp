#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start;
    int finish;
};

bool compareActivities(Activity a, Activity b) {
    return a.finish < b.finish;
}

void solveActivitySelection(int n, vector<int>& start, vector<int>& finish) {
    vector<Activity> activities(n);

    for (int i = 0; i < n; i++) {
        activities[i].start = start[i];
        activities[i].finish = finish[i];
    }

    sort(activities.begin(), activities.end(), compareActivities);

    vector<Activity> selectedActivities;

    selectedActivities.push_back(activities[0]);
    int lastFinishTime = activities[0].finish;

    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastFinishTime) {
            selectedActivities.push_back(activities[i]);
            lastFinishTime = activities[i].finish;
        }
    }

    cout << "Maximum number of activities = " << selectedActivities.size() << endl;
    cout << "Selected activities: ";
    
    for (int i = 0; i < selectedActivities.size(); i++) {
        cout << "(" << selectedActivities[i].start << ", " << selectedActivities[i].finish << ")";
        if (i < selectedActivities.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

int main() {
    int N = 6;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};

    solveActivitySelection(N, start, finish);

    return 0;
}