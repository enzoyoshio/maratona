#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n; cin >> n;
		vector<pair<int,int>> v(n);
		for(auto& [a, b]: v) cin >> a >> b;

		int cur = v.front().second;	
		map<int,int> f;
		for(int i = 1; i < n; i++)
			if(v[i].first >= v.front().first)
				f[v[i].second]++;
		bool can = true;
		for(auto [a, b]: f) {
			if(a >= cur) can = false;
		}
		if(can) cout << v.front().first << endl;
		else cout << -1 << endl;
	}
}
