#include <bits/stdc++.h>
using namespace std;
int main() {
int t;
cin>>t;
while(t--){
	long long n,d,h;
	cin>>n>>d>>h;
	long long arr[n];
	for (long long i = 0; i <n; ++i)
	{
		cin>>arr[i];
	}
	double ans=0;
	ans=(double)(d*h)/2;
if(n==1){
printf("%.7f\n",ans );
}
else{
	for (int i = 1; i <n; ++i)
	{
		double x=arr[i]-arr[i-1];
		if(x>h){
			double area=(double)((d)*(h))/2;
			ans+=area;
		}
		else {
			
			double w=(double)((d)*(h-x))/(h);
              double area=(double)((d+w)*(x))/2;
              ans+=area;
		}
	}
	
	printf("%.7f\n",ans );}
}


}
