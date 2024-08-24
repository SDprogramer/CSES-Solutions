#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "1" << endl;
    } else if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << endl;
    } else {
        // For n >= 4, we can separate the evens and odds.
        vector<int> evens, odds;
        for (int i = 2; i <= n; i += 2) {
            evens.push_back(i);  // Collect even numbers
        }
        for (int i = 1; i <= n; i += 2) {
            odds.push_back(i);   // Collect odd numbers
        }
        // Output the evens first
        for (int num : evens) {
            cout << num << " ";
        }
        // Followed by the odds
        for (int num : odds) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}