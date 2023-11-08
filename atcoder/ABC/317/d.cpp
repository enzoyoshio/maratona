#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e14;

using iii = array<int,3>;
const int MAXN = 1e5+2;

int n;
vector<iii> v;
vector<vector<int>> dp;

int f(int idx, int win) {
	
	if(win <= 0) return 0;

	if(idx >= n) {
		if(win) return oo;
		return 0;
	}

	auto& ans = dp[idx][win];
	if(~ans) return ans;

	int pega = oo, npega = oo;

	npega = f(idx+1, win);
	pega = max((v[idx][1] + v[idx][0] +1)/2 - v[idx][0], 0LL) +
		f(idx+1, win - v[idx][2]);

	return ans = min(pega, npega);
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n;
	v.resize(n);
	int toto = 0;
	dp.resize(n+2, vector<int>(MAXN, -1));
	for(auto& [a, b, c]: v) cin >> a >> b >> c, toto += c;

	cout << f(0, (toto+1)/2) << endl;

}
