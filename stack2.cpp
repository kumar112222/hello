
#include <bits/stdc++.h>
using namespace std;
int main(){
   int t;
   cin>>t;while(t--){
    int n;
    cin>>n;
    int arr[26]={0};
    int brr[26]={0};
    for (int i = 0; i <(2*n-2); ++i)
    {
    	char x;
    	cin>>x;
    	if(x>='a'&&x<='z'){
    		int y=(int)x-97;
    		arr[y]++;
    	}
    	else {
    		int y=(int)x-65;
    		brr[y]++;
    	}}
    	int count=0;
    	for (int i = 0; i <(2*n-2); ++i)
    {int x=brr[i]-arr[i];
      if(x>0) count+=x;}
      cout<<count<<endl;}
  }