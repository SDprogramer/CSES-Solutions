#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;

    long long total_sum_n = (n * (n + 1)) / 2;

    long long sum_given_nos = 0; 
    for (int i = 0; i < n - 1; i++) {
        int num;
        cin >> num;
        sum_given_nos += num;
    }

    int missing_no = total_sum_n - sum_given_nos;

    cout << missing_no << endl;

    return 0;

}