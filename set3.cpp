#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map<int,multiset<string>>m;
    for (int i = 0; i <n; ++i)
    {
        int x;
        string s;
        cin>>s>>x;
        m[-1*x].insert(s);
    }
    for(auto &pr:m){
        auto &student=pr.second;
        int marks=pr.first;
        for(auto students:student){
            cout<<students<<" "<<(-1)*marks<<endl;
        }
    }

return 0;
}