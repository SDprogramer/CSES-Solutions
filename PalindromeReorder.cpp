# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorderPalindrome(string s) {
        unordered_map<char, int> mp;

        for (char c : s) mp[c]++;

        int oddCount = 0;
        char oddChar = '\0';
        for (auto& entry : mp) {
            if (entry.second % 2 == 1) {
                oddCount++;
                oddChar = entry.first;
            }
        }

        if (oddCount > 1) return "NO SOLUTION";

        string firstHalf = "";
        for (auto& entry : mp) firstHalf += string(entry.second / 2, entry.first);

        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());

        if (oddCount == 1) return firstHalf + oddChar + secondHalf;

        return firstHalf + secondHalf;
    }
};

int main() {
    Solution sol;
    string input;
    cin >> input;
    cout << sol.reorderPalindrome(input) << endl;
    return 0;
}