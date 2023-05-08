#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	map<int,int> f;
	for(auto& it: v)
		cin >> it, f[it]++;

	int maxi = 0;
	vector<pair<int,int>> vp;
	for(auto [a, b]: f)
		vp.emplace_back(a, b), maxi = max(maxi, a);

	sort(begin(vp), end(vp));

	int ans = 0;
	for(int i = 0; i < (int)vp.size(); i++) {
		if(vp[i].second > 2)
			ans += vp[i].second * (vp[i].second-1) *(vp[i].second-2);
		for(int j = 2; j*j*vp[i].first <= maxi; j++) {
			auto p = lower_bound(begin(vp), end(vp), pair<int,int>(vp[i].first*j, -1));
			auto p2 = lower_bound(begin(vp), end(vp), pair<int,int>(vp[i].first*j*j, -1));

			if(p == end(vp) || p2 == end(vp)) continue;
			if(p->first != vp[i].first*j || p2->first != vp[i].first*j*j) continue;

			ans += vp[i].second * p->second * p2->second;
		}
	}

	cout << ans << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t=1;
	cin >> t;
	while(t--) solve();
}
