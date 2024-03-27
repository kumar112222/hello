#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, h;
        cin >> n >> m >> h;
        multimap<long long, long long> ms;
        long long ct = 0;
        long long pen = 0;
        for (int i = 0; i < n; ++i) {
            multiset<long long> s;
            for (int j = 0; j < m; ++j) {
                long long x;
                cin >> x;
                s.insert(x);
            }
            long long count = 0;
            long long sum = 0;
            long long time = 0;
            long long wr = 0;
            for (auto it = s.begin(); it != s.end(); ++it) {
                long long x = (*it);
                wr += (*it);
                if ((time + x) <= h) {
                    sum += wr;
                    time += x;
                    count++;
                }
            }
            if (i == 0) {
                pen = sum;
                ct = count;
            }
            ms.insert({ count, sum });
            s.clear();
        }
        long long rank = 1;
        for (auto &pr : ms)
        {
            if (pr.first == ct) {
                if (pr.second < pen) rank++;
            }
            else {
                if (pr.first > ct) rank++;
            }
        }

        cout << rank << endl;

    }
}