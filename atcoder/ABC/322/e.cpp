#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e18;
int n, k, p;
vector<int> cost;
vector<vector<int>> values;
int dp[103][7][7][7][7][7];

int f(int idx, int fi, int se, int th, int fo, int fif) {

	if(idx >= n) {
		if(fi >= p && se >= p && th >= p && fo >= p && fif >= p)
			return 0;
		return oo;	
	}

	auto& ans = dp[idx][fi][se][th][fo][fif];
	if(~ans) return ans;
	ans = oo;

	ans = min(ans, f(idx+1, fi, se, th, fo, fif));

	ans = min(ans, cost[idx] + f(idx+1, 
		min(5LL, fi + values[idx][0]),
		min(5LL, se + values[idx][1]), 
		min(5LL, th + values[idx][2]), 
		min(5LL, fo + values[idx][3]), 
		min(5LL, fif + values[idx][4])));
	return ans;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> k >> p;
	cost.resize(n);
	values.resize(n, vector<int>(5));
	memset(dp, -1, sizeof(dp));

	for(int i = 0; i < n; i++) {
		cin >> cost[i];
		for(int j = 0; j < k; j++)
			cin >> values[i][j];
	}

	int r = f(0, 
		0, 
		1 < k ? 0 : 5, 
		2 < k ? 0 : 5,
		3 < k ? 0 : 5,
		4 < k ? 0 : 5);
	if(r == oo) cout << -1 << endl; 
	else
		cout << r << endl; 
}
