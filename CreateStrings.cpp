#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    
    set<string> permutations;
    do {
        permutations.insert(s);
    } while (next_permutation(s.begin(), s.end()));
    
    cout << permutations.size() << endl;
    for (const auto& perm : permutations) {
        cout << perm << endl;
    }
    
    return 0;
}