#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, d;
	cin >> n >> d;
	vector<int> v(n), cost(n);
	for(auto& it: v) cin >> it;

	stack<int> st;
	for(int i = n-1; i >= 0; i--) {

		while(st.size() && v[i] >= v[st.top()]) st.pop();

		if(st.empty()) cost[i] = n-i;
		else cost[i] = st.top() - i;
		st.push(i);
	}

	vector<vector<int>> dp(n+1, vector<int>(d+1));

	for(int i = n-1; i >= 0; i--) {
		for(int qt = 0; qt <= d; qt++) {
			if(i + cost[i] <= n && qt) dp[i][qt] = max(dp[i][qt], cost[i] + dp[i+cost[i]][qt-1]);
			dp[i][qt] = max(dp[i][qt], dp[i+1][qt]);
		}
	}

	cout << dp[0][d] << endl;
}
