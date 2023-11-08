#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> v(k);
	vector<int> psum(n+2), has(n+2);
	for(auto& it: v) cin >> it, psum[it] = 1, has[it] = 1;
	has[0] = 1;

	for(int i = 1; i <= n; i++)
		psum[i] += psum[i-1];

	for(int i = m-1; i <= n; i++) {
		if(psum[i] - (i-m < 0 ? 0 : psum[i-m]) == m)
			return cout << -1 << endl, 0;
	}

	vector<double> dp(n+2);

	for(int i = 1; i <= n; i++) {

		double sum = 0;
		int qt = 0;
		for(int j = 0; j < m; j++) {
			if(has[max(0, i-1-j)])
				sum += dp[max(0, i-1-j)];
			if( i-1-j >= 0)
				qt += has[max(0, i-1-j)];	
		}

		dp[i] = (sum+m)/(m-qt);
	}
	cout << fixed << setprecision(20);
	cout << dp[n] << endl;
}
