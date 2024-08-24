#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;  // Number of test cases
    
    while (t--) {
        long long y, x;
        cin >> y >> x;
        
        long long max_val = max(y, x);
        long long result;
        
        if (max_val % 2 == 0) {
            if (y == max_val) {
                result = max_val * max_val - x + 1;
            } else {
                result = (max_val - 1) * (max_val - 1) + y;
            }
        } else {
            if (x == max_val) {
                result = max_val * max_val - y + 1;
            } else {
                result = (max_val - 1) * (max_val - 1) + x;
            }
        }
        cout << result << endl;
    }
    return 0;
}