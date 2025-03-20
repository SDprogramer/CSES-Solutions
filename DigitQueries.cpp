#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Function to find the digit at position k in the infinite string
char findDigitAtPosition(long long k) {
    long long length = 1;  // Length of the numbers in the current range
    long long count = 9;   // Number of numbers in the current range
    long long start = 1;   // First number in the current range

    // Step 1: Find the range where the k-th digit resides
    while (k > length * count) {
        k -= length * count;
        length++;
        count *= 10;
        start *= 10;
    }

    // Step 2: Find the exact number that contains the k-th digit
    long long number = start + (k - 1) / length;

    // Step 3: Find the exact digit within that number
    int digitIndex = (k - 1) % length;
    string numStr = to_string(number);
    return numStr[digitIndex];
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        long long k;
        cin >> k;
        cout << findDigitAtPosition(k) << endl;
    }
    return 0;
}