#include <iostream>
using namespace std;

bool canEmptyPiles(int a, int b) {
    // Make sure that a is always the larger or equal to b
    if (a < b) swap(a, b);

    // Check the conditions for being able to empty the piles
    if ((a + b) % 3 == 0 && a <= 2 * b) {
        return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        if (canEmptyPiles(a, b)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
