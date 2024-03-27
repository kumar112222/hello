#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n; std::vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		double x; cin >> x;
		double y = sqrt(x);
		if (x == 1) v.push_back(0);
		else {
			if (y == (int)y) v.push_back(y);
			else v.push_back(0);
		}
	}
	int N=1e6+10;
	vector<bool> isPrime(N, 1);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= N; i++)
	{
		if (isPrime[i] == true)
		{
			for (long long  j = (long long)i * i; j < N; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
	for (int i = 0; i <n; ++i)
	{
		if(v[i]==0) cout<<"NO"<<endl;
		else{
			if(isPrime[v[i]]==true) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
}