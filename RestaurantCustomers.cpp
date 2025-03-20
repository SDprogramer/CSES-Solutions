#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    // Create a vector of events
    vector<pair<int, int>> events; // {time, type}
    // type: +1 for arrival, -1 for departure

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, 1});  // Arrival event
        events.push_back({b, -1}); // Departure event
    }

    // Sort events
    // If two events have the same time, process departure first
    sort(events.begin(), events.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
        if (x.first == y.first) {
            return x.second < y.second;
        }
        return x.first < y.first;
    });

    int current_customers = 0;
    int max_customers = 0;

    // Process events
    for (const auto& event : events) {
        current_customers += event.second; // Update current customers
        max_customers = max(max_customers, current_customers); // Update maximum
    }

    cout << max_customers << endl;

    return 0;
}