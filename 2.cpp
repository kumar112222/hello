#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

void solve() {
    string s;
    cin >> s;
    ll n = s.size(); 
    ll ans = 0;
    for (ll i = 0; i < 10; ++i) {
        for (ll j = 0; j < 10; ++j) {
            ll count = 0;
            for (ll k = 0; k < n; ++k) {
                if (count % 2 == 0 && (s[k] - '0') == i)
                    count++;
                else if ((s[k] - '0') == j)
                    count++;
            }
            if (i == j)
                ans = max(ans, count);
            else
                ans = max(ans, count / 2 * 2);
        }
    }
    cout << n - ans << endl;
}

int main() {
    solve();
    return 0;
}
