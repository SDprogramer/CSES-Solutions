#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long findMinDifference(int n, vector<long long>& weights) {
    long long totalSum = 0;
    for (long long weight : weights) {
        totalSum += weight;
    }

    long long minDiff = LLONG_MAX;

    // Iterate over all possible subsets
    for (int mask = 0; mask < (1 << n); ++mask) {
        long long subsetSum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subsetSum += weights[i];
            }
        }
        long long diff = abs(totalSum - 2 * subsetSum);
        if (diff < minDiff) {
            minDiff = diff;
        }
    }

    return minDiff;
}

int main() {
    int n;
    cin >> n;
    vector<long long> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    long long result = findMinDifference(n, weights);
    cout << result << endl;

    return 0;
}