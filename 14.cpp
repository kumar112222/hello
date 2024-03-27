#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int  dp[50005];

int func(vector<int>&arr, int index, int n, vector<bool>&visited) {
    if (index >= n || index < 0)return 0;
    if (arr[index] == 0)return 1;
    if (dp[index] != -1)return dp[index];
    int flag = 0;
    visited[index] = true;
    if (index + arr[index] < n && index + arr[index] >= 0 && !visited[index + arr[index]] ) {
        flag |= func(arr, index + arr[index], n, visited);
    }
    if (index - arr[index] >= 0 && index - arr[index] < n && !visited[index - arr[index]]) {
        flag |= func(arr, index - arr[index], n, visited);
    }
    return dp[index] = flag;
}
bool canReach(vector<int>& arr, int start) {
    int n = arr.size();
    memset(dp, -1, sizeof(dp));
    vector<bool>visited(50005, false);
    if (func(arr, start, n,visited))return true;
    return false;
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int>v(n);
    for (int i = 0; i < n; ++i)
    {
        /* code */cin >> v[i];
    }
    cout << canReach(v, k) << endl;


}


int main() {
    ios_base::sync_with_stdio(false),
             cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

}