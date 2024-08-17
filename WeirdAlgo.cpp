#include <bits/stdc++.h>
using namespace std;

void check (long long n) {
    while (n != 1) {
        cout << n << " ";
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = (n * 3) + 1;
        }
    }
    cout << n << endl;
}

int main() {
    long long n;
    cin >> n;

    check(n);

    return 0;
}