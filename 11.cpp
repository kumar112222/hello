#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	int n;
	cin >> n;
	vector<int>v1(n + 3), v2(n + 3), prefix(n), suffix(n); int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		/* code */cin >> v1[i];
	}
	for (int i = 1; i <= n ; ++i)
	{
		/* code */cin >> v2[i]; ans += (v1[i] * v2[i]);
	}
	vector<vector<int>>dp(n + 10, vector<int>(n + 10));
	// cout << ans << endl;
	int maxm = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i - 1; j >= 1; --j)
		{
			// cout << dp[j + 1][i - 1] - (v1[j] * v2[j]) - (v1[i] * v2[i]) + (v1[j] * v2[i]) + (v1[i] * v2[j]) << endl;
			/* code */dp[j][i] = dp[j + 1][i - 1] - (v1[j] * v2[j]) - (v1[i] * v2[i]) + (v1[j] * v2[i]) + (v1[i] * v2[j]);
			maxm = max(maxm, dp[j][i]);
		}
	}
	// cout << maxm << endl;
	cout << ans + maxm << endl;


}


int main() {
	ios_base::sync_with_stdio(false),
	         cin.tie(nullptr);
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

}