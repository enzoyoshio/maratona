#include <bits/stdc++.h>

using namespace std;
#define int long long

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"

const int MOD = 998244353;

int add(int a, int b) { return (a+b)%MOD;}
int mul(int a, int b) { return (a*b)%MOD;}

int n;
vector<int> cost;
vector<vector<int>> tab;

int dp(int idx, int w) {

	if(idx >= n) {
		return w == 0;
	}

	if(w == 0) {
		return n-idx+1;
	}

	auto& ans = tab[idx][w];
	if(~ans) return ans;
	ans = 0;

	ans = add(ans, dp(idx+1, w));

	/*
	cerr << " =----------------------- \n";
	db(idx);
	db(w);
	db(ans);
	*/

	if(w - cost[idx] >= 0) {
		ans = add(ans, mul(1, dp(idx+1, w-cost[idx])));
	}

	/*
	cerr << " =----------------------- \n";
	db(idx);
	db(w);
	db(ans);
	*/

	return ans;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int s;
	cin >> n;
	cin >> s;
	cost.resize(n);
	for(auto& el: cost) cin >> el;
//	tab.resize(n+2, vector<int>(s+2, 0));
	vector<int> tb(s+2, 0);

	tb[0] = 1;

	int ans = 0;
	for(int idx = n-1; idx >= 0; idx--) {
		for(int w = s; w >= 0; w--) {
			auto& ans = tb[w];
			if(w - cost[idx] >= 0) {
				ans += tb[w-cost[idx]];
				if(ans >= MOD) ans -= MOD;
			}

		}
		ans += tb[s];
		if(ans >= MOD) ans -= MOD;
		tb[0]++;
	}

	cout << ans << endl;
}
