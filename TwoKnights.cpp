#include <iostream>
using namespace std;

void calculateKnightPlacements(int n) {
    for (long long int k = 1; k <= n; k++) {
        long long int totalWays = (k * k * (k * k - 1)) / 2;
        long long int attackingWays = 0;
        if (k > 2) {
            attackingWays = 4 * (k - 1) * (k - 2);
        }
        long long int nonAttackingWays = totalWays - attackingWays;
        cout << nonAttackingWays << endl;
    }
}

int main() {
    int n;
    cin >> n;
    calculateKnightPlacements(n);
    return 0;
}