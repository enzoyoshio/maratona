#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e15;
int n;
vector<int> v;

int ff(int idx, int qt, auto& dp) {

	if(idx >= n) {
		if(qt) return oo;
		return 0;
	}

	if(~dp[idx][qt]) return dp[idx][qt];

	int pega = oo, npega = oo;

	if(qt) pega = v[idx] + ff(idx+1, qt-1, dp);
	npega = ff(idx+1, qt, dp);

	return dp[idx][qt] = min(pega, npega);
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int w, f, total = 0;
		cin >> w >> f >> n;
		v.resize(n);
		for(auto& it: v) cin >> it, total += it;

		vector dp(n+2, vector<int>(n+2, -1));

		/*
		for(int i = 1; i <= n; i++)
			dp[n][i] = oo;

		for(int idx = n-1; idx >= 0; idx--) {
			for(int qt = 0; qt <= n; qt++) {
			
				auto& ans = dp[idx][qt];

				if(qt)
					ans = min(ans, dp[idx+1][qt-1] + v[idx]);
				ans = min(ans, dp[idx+1][qt]);

				cout << "processing ";
				cout << ans << ' ' << ff(idx, qt) << endl;;
			}
		}
		*/

		int ans = oo;
		for(int i = 0; i <= n; i++) {
			int left = ff(0, i, dp);
			cout << left << ' ';
			cout << ff(0, i, dp) << endl;

			int right = total - left;

			// quantos feiticos de agua pra matar left?
			// quantos feiticos de fogo pra matar right?
			
			ans = min(ans, max(
			   (!left ? oo : (w+left-1)/left * left),
			   (!right ? oo : (f+right-1)/right * right)));
			
			// fazer o contrario
			// quantos feiticos de fogo pra matar left?
			// quantos feiticos de agua pra matar right?
	
			ans = min(ans, max(
			   (!left ? oo : (f+left-1)/left * left),
			   (!right ? oo : (w+right-1)/right * right)));
		}
		cout << endl;
		cout << ans << '\n';

	}
}
