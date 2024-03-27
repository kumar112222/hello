#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin>>t;while(t--){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    int ans = 0;
    do {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            set<int> s;
            for (int j = i; j < n; j++) {
                s.insert(a[j]);
                if (*s.begin() == 1) {
                    continue;
                }
                bool ok = true;
                for (int k = 2; k * k <= *s.begin(); k++) {
                    if (*s.begin() % k == 0) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    cnt++;
                }
            }
        }
        ans = max(ans, cnt);
    } while (next_permutation(a.begin(), a.end()));
    cout << ans << endl;
}
    return 0;
}
