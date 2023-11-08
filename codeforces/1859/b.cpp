#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e18;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n; cin >> n;
		vector<vector<int>> v(n);
		vector<pair<int,int>> p(n);

		for(int i = 0; i < n; i++) {
			int sz; cin >> sz;
			for(int j = 0; j < sz; j++) {
				int a; cin >> a;
				v[i].push_back(a);
			}
			sort(begin(v[i]), end(v[i]));
			p[i] = {v[i][0], v[i][1]};
		}

		sort(begin(p), end(p));
		vector<int> pmin(n), smin(n);
		pmin[0] = p[0].first;
		for(int i = 1; i < n; i++) {
			pmin[i] = p[i].first;
			pmin[i] = min(pmin[i], pmin[i-1]);
		}
		smin.back() = p.back().first;
		for(int i = n-2; i >= 0; i--) {
			smin[i] = p[i].first;
			smin[i] = min(smin[i+1], smin[i]);
		}

		int sum = 0;
		for(int i = 0; i < n; i++)
			sum += p[i].second;

		int ans = 0;
		for(int i = 0; i < n; i++) {
			int esq = (i ? pmin[i-1] : p[i].first);
			int dir = (i+1 < n ? smin[i+1] : p[i].first);
			ans = max(ans, sum - p[i].second + min(esq, dir));
		}
		cout << ans << '\n';
	}
}
