#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        unordered_set<long long> m1;
        
        for (int i = 0; i < m; ++i) {
            long long x;
            cin >> x;
            m1.insert(x);
        }
        for (int i = 0; i < n; ++i) {
            long long x;
            cin >> x;
            auto it = m1.find(x);
            if (it == m1.end()) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
            m1.insert(x);
        }
    }
    return 0;
}
