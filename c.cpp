#include <bits/stdc++.h>
using namespace std;

int func(int sum, int n, vector<int>& v) {
    if (sum == 0) return 0; // Base case: sum is already 0, no need for any coins.
    if (sum < 0) return -1; // If sum becomes negative, it means no solution is possible.
    
    int final = INT_MAX; // Initialize final result to maximum value.
    
    for (int i = 0; i < n; ++i) {
        int res = func(sum - v[i], n, v); // Recursively call func for remaining sum.
        if (res != -1) { // If a valid solution is found.
            final = min(final, res + 1); // Update final result with the minimum number of coins.
        }
    }
    
    if (final == INT_MAX) return -1; // If final is still INT_MAX, no valid solution was found.
    return final; // Return the minimum number of coins needed.
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cout << func(k, n, v) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
