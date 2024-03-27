#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif


typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
//typedef __int128 ell;
//typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds;

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
bool check(int n) {
	bool is_prime = true;
	if (n == 1)
	{
		// cout << 0 << endl;
		return false;
	}
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			is_prime = false;
			break;
		}
	}
	return is_prime;
}


void solve() {
	int n;
	cin >> n;
	vector<int>v(n); ll sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i]; if (i % 2 == 0) sum1 += v[i];
		else sum2 += v[i];
	}
	debug(sum1);

	if (sum1 >= sum2) {
		for (int i = 0; i < n; ++i)
		{
			if (i % 2 == 0) cout << v[i] << " ";
			else cout << 1 << " ";
		}
	}
	else {
		for (int i = 0; i < n; ++i)
		{
			if (i % 2 != 0) cout << v[i] << " ";
			else cout << 1 << " ";
		}
	} cout << endl;



}


int main() {

	ios_base::sync_with_stdio(false),
	         cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

}
