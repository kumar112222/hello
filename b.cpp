#include <iostream>
#include <cstring> // for memset
using namespace std;

typedef long long ll;

ll count = 0;

void dfs(ll n, ll m, ll l, ll arr[][100], ll x, ll y) {
    if (x < 0 || x >= n || y < 0 || y >= m || arr[x][y] == 0)
        return;

    count++;
    arr[x][y] = 0; // Mark visited

    if (x - l >= 0 && arr[x - l][y] == 1) dfs(n, m, l, arr, x - l, y);
    if (x + l < n && arr[x + l][y] == 1) dfs(n, m, l, arr, x + l, y);
    if (y - l >= 0 && arr[x][y - l] == 1) dfs(n, m, l, arr, x, y - l);
    if (y + l < m && arr[x][y + l] == 1) dfs(n, m, l, arr, x, y + l);
}

void solve() {
    ll n, m, x, y, l;
    cin >> n >> m >> x >> y >> l;

    ll arr[100][100]; // Assuming maximum size
    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j]; // Input the grid

    count = 0;
    dfs(n, m, l, arr, x, y);

    cout << count << endl;
}

int main() {
    solve();
    return 0;
}
