#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	int arr[n];
	int brr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i]>>brr[i];
	}
	int count=0;
	for (int i = 0; i <n; ++i)
	{
		int x=arr[i]-brr[i];
		if(x>0) count++;
	}
	cout<<count<<endl;
	}
return 0;
}