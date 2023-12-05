#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start, finish;
};

bool compareActivities(const Activity& a, const Activity& b) {
    return a.finish < b.finish;
}

void activitySelection(const vector<Activity>& activities) {
    int n = activities.size();

    vector<Activity> sortedActivities = activities;
    sort(sortedActivities.begin(), sortedActivities.end(), compareActivities);

    cout << "Selected Activity: (" << sortedActivities[0].start << ", " << sortedActivities[0].finish << ")\n";

    int prevFinishTime = sortedActivities[0].finish;
    for (int i = 1; i < n; i++) {
        if (sortedActivities[i].start >= prevFinishTime) {
			cout << "Selected Activity: (" << sortedActivities[i].start << ", " << sortedActivities[i].finish << ")\n";
            prevFinishTime = sortedActivities[i].finish;
        }
    }
}

int main() {
    vector<Activity> activities = { {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}
    };

    cout << "Activities:\n";
    for (const auto& activity : activities) {
        cout << "(" << activity.start << ", " << activity.finish << ") ";
    }
    cout << "\n";

    cout << "\nSelected Activities:\n";
    activitySelection(activities);

    return 0;
}

