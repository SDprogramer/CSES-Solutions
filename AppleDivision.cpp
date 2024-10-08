#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> weights(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    
    long long totalSum = accumulate(weights.begin(), weights.end(), 0LL);
    long long target = totalSum / 2;

    // DP array to check reachable sums
    vector<bool> dp(target + 1, false);
    dp[0] = true; // 0 sum is always possible

    for (long long weight : weights) {
        // Check if the weight is less than or equal to target to avoid overflow
        if (weight > target) {
            continue;
        }
        for (long long j = target; j >= weight; --j) {
            if (dp[j - weight]) {
                dp[j] = true;
            }
        }
    }

    // Find the largest j such that dp[j] is true
    long long sum1;
    for (sum1 = target; sum1 >= 0; --sum1) {
        if (dp[sum1]) {
            break;
        }
    }
    
    long long sum2 = totalSum - sum1;
    
    // The minimum difference
    cout << abs(sum1 - sum2) << endl;

    return 0;
}
