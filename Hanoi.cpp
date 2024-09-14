#include <bits/stdc++.h>
using namespace std;

int countMoves = 0;

void hanoi(int n, int a, int b, int c) {
    if (n == 0) return;
    hanoi(n - 1, a, c, b); // Move n-1 disks from a to b using c as auxiliary
    cout << a << " " << c << endl; // Move nth disk from a to c
    countMoves++; // Increment the move count
    hanoi(n - 1, b, a, c); // Move n-1 disks from b to c using a as auxiliary
}

int main() {
    int n;
    cin >> n;
    
    // Total number of moves for n disks is 2^n - 1
    int totalMoves = (1 << n) - 1;
    cout << totalMoves << endl;
    
    // Solve Tower of Hanoi with three stacks 1, 2, 3
    hanoi(n, 1, 2, 3);
    
    return 0;
}
