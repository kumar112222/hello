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
		int n;
		cin >> n; vector<int>v;
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin >> x; v.push_back(x);
		}
		vector<int>ans; vector<int>b;
		int a = 0; for (int i = 1; i < n; ++i)
		{
			if (v[i] != v[i - 1]) {
				a = 1; break;
			}
		}
		if (a == 0) {
			cout << -1 << endl;

		}
		else {
			int index = -1;
			sort(v.begin(), v.end()); ans.push_back(v[0]);
			for (int i = 1; i < n; ++i)
			{
				if (v[i - 1] % v[i] == 0) {
					ans.push_back(v[i]);
				}
				else {
					index = i;
					break;
				}
			}
			for (int i = index; i < n; ++i)
			{
				b.push_back(v[i]);
			}
			cout << ans.size() << " " << b.size() << endl;
			for (int i = 0; i < ans.size(); ++i)
			{
				cout << ans[i] << " ";
			} cout << endl;
			for (int i = 0; i <b.size(); ++i)
			{
				cout << b[i] << " ";
			} cout << endl;
		}
	}
	return 0;
}