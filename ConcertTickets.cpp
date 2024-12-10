#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> ticketPrices(n);
    vector<int> customerOffers(m);

    for (int i = 0; i < n; ++i) {
        cin >> ticketPrices[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> customerOffers[i];
    }

    // Use a multiset to store ticket prices (supports efficient insertion and deletion)
    multiset<int> tickets(ticketPrices.begin(), ticketPrices.end());

    for (int offer : customerOffers) {
        auto it = tickets.upper_bound(offer); // Find the first ticket with a price > offer
        if (it == tickets.begin()) {
            cout << -1 << endl; // No suitable ticket
        } else {
            --it; // Get the largest ticket price <= offer
            cout << *it << endl;
            tickets.erase(it); // Remove the ticket from available tickets
        }
    }

    return 0;
}