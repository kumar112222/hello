#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	vector<bool>prime(n + 2, 1);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= n + 1; ++i)
	{
		if (prime[i] == true) {
			for (int j = 2 * i; j <= n + 1; j += i) {
				prime[j] = false;
			}
		}
	} vector<int>ans; int count = 0;
	for (int i = 2; i < n + 2; ++i)
	{
		if (prime[i] == 1) {
			ans.push_back(2);
		}
		else ans.push_back(1);
	} int a = 0;
	for (int i = 0; i < ans.size(); ++i)
	{
		if (ans[0] != ans[i]) a = 1;
	}
	if (a) cout << 2 << endl;
	else cout << 1 << endl;
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << " ";
	} cout << endl;
}