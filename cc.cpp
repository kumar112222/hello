#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	ll n;
	cin >> n;
	vector<ll>v(n);
	for (ll i = 0; i < n; ++i)
	{
		/* code */cin >> v[i];
	}
	for (ll i = 0; i < n; ++i)
	{	bool flag = true;
		for (ll j = i + 1; j >= 1; --j)
		{
			/* code */if (v[i] % (j + 1) != 0) {
				flag = false; break;
			}
		}
		if (flag) {
			cout << "NO" << endl; return;
		}
	}
	cout << "YES" << endl;


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