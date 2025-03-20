#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxMovies(int n, vector<pair<int, int>>& movies) {
    // Sort movies based on ending time
    sort(movies.begin(), movies.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int count = 0;
    int lastEndTime = 0;

    for (const auto& movie : movies) {
        int start = movie.first;
        int end = movie.second;

        if (start >= lastEndTime) {
            count++;
            lastEndTime = end;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> movies(n);

    for (int i = 0; i < n; i++) {
        cin >> movies[i].first >> movies[i].second;
    }

    int result = maxMovies(n, movies);
    cout << result << endl;

    return 0;
}