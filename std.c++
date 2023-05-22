#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323
#define ll long long int
#define vi vector <int>
#define vl vector <ll>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
ll power(ll a, ll b) { //a^b
	ll res = 1;
	a = a % MOD;
	while (b > 0) {
		if (b & 1) {res = (res * a) % MOD; b--;}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin >> t;
	ll T = 1;
	while (t--) {
		ll n, m, p, sx, sy;
		cin >> n >> p >> m >> sx >> sy;
		sx--;
		sy--;
		assert(p == 0);
		vector <pair<char, ll>> dir(4);
		for (auto &i : dir)
			cin >> i.ff >> i.ss;
		ll dp[n][n][m + 1];
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < n; j++) {
				for (ll k = 0; k <= m; k++)
					dp[i][j][k] = -1e17;
			}
		}
		dp[sx][sy][0] = 0;
		for (ll k = 1; k <= m; k++) {
			for (ll i = 0; i < n; i++) {
				for (ll j = 0; j < n; j++) {
					if (i) {
						ll newval = dp[i - 1][j][k - 1];
						if (dir[3].ff == '+')
							newval += dir[3].ss;
						else if (dir[3].ff == '-')
							newval -= dir[3].ss;
						else if (dir[3].ff == '/') {
							int fl = 0;
							ll prev;
							if (newval < 0) {
								fl = 1;
								newval *= -1;
								prev = newval;
							}
							newval /= dir[3].ss;
							if (fl) {
								newval *= -1;
							}
							if (fl && prev % dir[3].ss) {
								newval--;
							}
						}
						else if (dir[3].ff == '*')
							newval *= dir[3].ss;
						dp[i][j][k] = max(dp[i][j][k], newval);
					}
					if (j) {
						ll newval = dp[i][j - 1][k - 1];
						if (dir[1].ff == '+')
							newval += dir[1].ss;
						else if (dir[1].ff == '-')
							newval -= dir[1].ss;
						else if (dir[1].ff == '/') {
							int fl = 0;
							ll prev;
							if (newval < 0) {
								fl = 1;
								newval *= -1;
								prev = newval;
							}
							newval /= dir[1].ss;
							if (fl) {
								newval *= -1;
							}
							if (fl && prev % dir[1].ss) {
								newval--;
							}
						}
						else if (dir[1].ff == '*')
							newval *= dir[1].ss;
						dp[i][j][k] = max(dp[i][j][k], newval);
					}
					if (i + 1 < n) {
						ll newval = dp[i + 1][j][k - 1];
						if (dir[0].ff == '+')
							newval += dir[0].ss;
						else if (dir[0].ff == '-')
							newval -= dir[0].ss;
						else if (dir[0].ff == '/') {
							int fl = 0;
							ll prev;
							if (newval < 0) {
								fl = 1;
								newval *= -1;
								prev = newval;
							}
							newval /= dir[0].ss;
							if (fl) {
								newval *= -1;
							}
							if (fl && prev % dir[0].ss) {
								newval--;
							}
						}
						else if (dir[0].ff == '*') {
							newval *= dir[0].ss;
						}
						dp[i][j][k] = max(dp[i][j][k], newval);
					}
					if (j + 1 < n) {
						ll newval = dp[i][j + 1][k - 1];
						if (dir[2].ff == '+')
							newval += dir[2].ss;
						else if (dir[2].ff == '-')
							newval -= dir[2].ss;
						else if (dir[2].ff == '/') {
							int fl = 0;
							ll prev;
							if (newval < 0) {
								fl = 1;
								newval *= -1;
								prev = newval;
							}
							newval /= dir[2].ss;
							if (fl) {
								newval *= -1;
							}
							if (fl && prev % dir[2].ss) {
								newval--;
							}
						}
						else if (dir[2].ff == '*')
							newval *= dir[2].ss;
						dp[i][j][k] = max(dp[i][j][k], newval);
					}
					dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1]);
				}
			}
		}
		ll ans = -1e17;
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < n; j++)
				ans = max(dp[i][j][m], ans);
		}
		cout << "Case #" << T << ": " << ans << "\n";
		T++;
	}
}

