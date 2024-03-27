#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mp make_pair
#define pb push_back
#define loop(i, a, b) for (int i = a; i < b; i++)
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n; cin >> n;
		vector<pair<int, int>>v;
		for (int i = 0; i < n; ++i)
		{
			int x; cin >> x;
			v.push_back({x, i + 1});
		}
		sort(v.begin(), v.end());
		vector<pair<int, int>>ans;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				while (v[i].first < v[j].first) {
					if (v[j].first % v[i].first == 0) {
						v[j] .first/= v[i].first;
						int x = v[i].second, y = v[j].second;
						ans.push_back({x, y});
					}
					else {
						v[j].first = (v[j].first / v[i].first) + 1;
						int x = v[i].second, y = v[j].second;
						ans.push_back({x, y});
					}
				}
			}
		}
		int a = 0;
		for (int i = 1; i < n; ++i)
		{
			if (v[i].first != v[i - 1].second) {
				cout << -1 << endl;
				a = 1; break;
			}
		}
		if (a == 0) {
			cout << ans.size() << endl;
			for (int i = 0; i < ans.size(); ++i)
			{
				cout << ans[i].first << " " << ans[i].second << endl;
			}
		}
	}
	return 0;
}