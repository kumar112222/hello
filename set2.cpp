#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
	set<string>s;
	for (int i = 0; i <n; ++i)
	{
		string m;
		cin>>m;
		s.insert(m);
	}
	for(string value:s){
		cout<<value<<endl;
	}
	}
return 0;
}