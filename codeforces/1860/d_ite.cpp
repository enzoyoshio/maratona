#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9;
signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	int ct = 0;
	string s;
	cin >> s;
	n = s.size();
	for(auto ch: s) ct += ch == '0';

	vector dp(2, vector<vector<int>>(n, vector<int>(n*n)));

	int zerish = n*n/2;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n*n; j++) {
			if(i != ct || j-zerish) dp[1][i][j] = oo;
		}
	}

	for(int idx = n-1; idx >= 0; idx--) {
		for(int zeros = idx; zeros >= 0; zeros--) {
			for(int endZ = 0; endZ < n*n; endZ++) {

				int um = oo;
				if(endZ - zeros >= 0)
					um = (s[idx] != '1')
					+ dp[1][zeros][endZ-zeros];
				int zero = oo;
				int leftOnes = idx - zeros;
				if(endZ + leftOnes < n*n
				&& zeros+1 < n)
					zero = (s[idx] != '0')
					+ dp[1][zeros+1][endZ+leftOnes];
				dp[0][zeros][endZ] = min(um, zero);
			}
		}
		swap(dp[0], dp[1]);

	}
	if(dp[1][0][zerish] == oo) cout << 0 << endl;
	else 
		cout << dp[1][0][zerish]/2 << '\n';
}
