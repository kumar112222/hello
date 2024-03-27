#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	long long int x = ((n) * (n + 1)) / 2;
	vector<long long int>v;
	for (int i = 0; i < n; ++i)
	{
		long long int y; cin >> y; v.push_back(y);
	}
	if (v[0] == 1) {
		long long sum = 1;int a=0;
		for (int i = 1; i < n; ++i)
		{
			long long z = v[i] - v[i - 1];
			sum += z;
			if (sum <= x) continue;
			else {a=1;
				cout << "NO" << endl;
				break;
			}
		}
		if(!a) cout<<"YES"<<endl;
	}



}