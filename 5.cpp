#include <iostream>
#include <vector>
#include <cstring> // for memset
using namespace std;

bool func(vector<int>& arr, int index, int n, vector<bool>& visited) {
    if (index >= n || index < 0 || visited[index])
        return false;
    if (arr[index] == 0)
        return true;

    visited[index] = true;
    bool flag = false;
    if (index + arr[index] < n && index + arr[index] >= 0) {
        flag |= func(arr, index + arr[index], n, visited);
    }
    if (index - arr[index] >= 0 && index - arr[index] < n) {
        flag |= func(arr, index - arr[index], n, visited);
    }
    return flag;
}

bool canReach(vector<int>& arr, int start) {
    int n = arr.size();
    vector<bool> visited(n, false); // Initialize visited array
    if (func(arr, start, n, visited))return true;
    return false;
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
