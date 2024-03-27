#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mp make_pair
#define pb push_back
#define loop(i, a, b) for (int i = a; i < b; i++)

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }

        // Sort the vector in ascending order
        sort(v.begin(), v.end());

        vector<int> ans(n + 1, 0);
        int a = 0;
        for (int i = 0; i < n; ++i)
        {
            if (v[i] > 1)
            {
                for (int j = v[i]; j <= n; j += v[i])
                {
                    ans[j]++;
                }
            }
            else
            {
                a++;
            }
        }

        if (a >= 1)
        {
            cout << (*max_element(ans.begin(), ans.end())) + a << endl;
        }
        else
        {
            cout << *max_element(ans.begin(), ans.end()) << endl;
        }
    }
    return 0;
}
