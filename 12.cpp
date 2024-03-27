#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll m = 1e9 + 7;
ll ncr(ll n, ll r) {
    ll ans = 1, final = 1;
    ll count = 0;
    ll x = r;
    while (count < r) {
        ans *= n;
        n--;
        while (x > 0 && ans % x == 0) {
            ans /= x; x--;
        }
        // ans %= m;
        count++;
    }
    while (x > 0) {
        ans /= x; x--;
    }
    return ans % m;
}
void solve() {
    ll n, k;
    cin >> n >> k; map<ll, ll>mp;
    vector<ll>v(n);
    for (ll i = 0; i < n; ++i)
    {
        /* code */cin >> v[i]; mp[v[i]]++;
    }
    sort(v.begin(), v.end());
    ll x = v[n - k];
    ll y = 0;
    for (ll i = n - 1; i >= 0; --i)
    {
        /* code */if (v[i] == x) {
            y = i; break;
        }
    }
    y = k - (n - 1 - y);
    cout << ncr(mp[x], y) % m << endl;


}


int main() {
    ios_base::sync_with_stdio(false),
             cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

}