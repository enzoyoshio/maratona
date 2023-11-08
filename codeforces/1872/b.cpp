#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n;
		cin >> n;
		vector<pair<int,int>> v(n);
		for(auto& [a, b]: v) cin >> a >> b;

		int ans = n+300;
		for(auto [a, b]: v) ans = min(ans, a + (b-1)/2);
		cout << ans << '\n';
	}
}
