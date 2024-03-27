#include<bits/stdc++.h>
using namespace std;
// #define int long long

void solve() {
	long long n, k;
	cin >> n >> k;
	vector<long long>a(n), b; multiset<long long>s;
	for (long long i = 0; i < n; ++i)
	{
		/* code */cin >> a[i]; s.insert(a[i]);
		// b.push_back(a[i]);
	}
	sort(a.begin(), a.end());
	long long ans = a[0];
	if (k >= 3) {
		cout << 0 << endl; return;
	}
	if (k == 1) {
		for (long long i = 0; i < n; ++i)
		{
			for (long long j = i + 1; j < n; ++j)
			{
				ans = min(abs(a[i] - a[j]), ans);
			}
		}
		cout << ans << endl; return;
	}
	for (long long i = 0; i < n; ++i)
	{
		for (long long j = 0; j < i; ++j)
		{
			long long x = a[i] - a[j];
			ans = min(ans, x);
			int p = lower_bound(begin(a), end(a), x) - begin(a);
			if (p < n) ans = min(ans, a[p] - x);
			if (p > 0) ans = min(ans, x - a[p - 1]);
		}
	}

	cout << ans << endl;



}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
