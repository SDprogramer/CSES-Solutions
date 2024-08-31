#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long sum = (long long)n * (n + 1) / 2;
    
    // Check if the sum is odd
    if (sum % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    vector<int> set1, set2;
    long long target_sum = sum / 2;
    long long current_sum = 0;
    
    // Greedily fill the first set
    for (int i = n; i >= 1; --i) {
        if (current_sum + i <= target_sum) {
            set1.push_back(i);
            current_sum += i;
        } else {
            set2.push_back(i);
        }
    }

    // Output the sets
    cout << set1.size() << endl;
    for (int x : set1) {
        cout << x << " ";
    }
    cout << endl;
    
    cout << set2.size() << endl;
    for (int x : set2) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}
