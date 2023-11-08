#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n, k;
		cin >> n >> k;
		vector<vector<int>> v(k);

		for(int i = 0; i < k; i++)
			v[i].push_back(0);

		for(int i = 0; i < n; i++) {
			int a; cin >> a;
			a--;
			v[a].push_back(i+1);
		}

		for(int i = 0; i < k; i++)
			v[i].push_back(n+1);

		int ans = (int)1e6;
		for(int i = 0; i < k; i++) {
			if(v[i].empty()) continue;

			multiset<int> sizes;
			for(int j = 1; j < v[i].size(); j++) {
				sizes.insert(abs(v[i][j]-v[i][j-1]) -1);
			}
			auto el = *rbegin(sizes);
			sizes.erase(sizes.find(el));
			sizes.insert(el/2);
			sizes.insert((el-1)/2);

			ans = min(ans, *rbegin(sizes));
		}
		cout << ans << '\n';

	}
}
