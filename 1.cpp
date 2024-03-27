#include <iostream>
#include <vector>
#include <cstring> // for memset
using namespace std;

int dp[50005];

bool func(vector<int>& arr, int index, int n) {
    if (index >= n || index < 0)
        return false;
    if (arr[index] == 0)
        return true;
    if (dp[index] != -1)
        return dp[index];

    bool flag = false;
    if (index + arr[index] < n && index + arr[index] >= 0) {
        flag = flag || func(arr, index + arr[index], n);
    }
    if (index - arr[index] >= 0 && index - arr[index] < n) {
        flag = flag || func(arr, index - arr[index], n);
    }
    return dp[index] = flag;
}

bool canReach(vector<int>& arr, int start) {
    int n = arr.size();
    memset(dp, -1, sizeof(dp));
    return func(arr, start, n);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cout << (canReach(v, k) ? "true" : "false") << endl;

    return 0;
}
