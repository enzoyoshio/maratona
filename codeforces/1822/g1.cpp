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

	for(auto [a, b]: f) {
		if(b > 2)
			ans += b*(b-1)*(b-2);

		for(int j = 2; j*j*a <= maxi; j++) {
			if(f.find(a*j) == f.end() || f.find(a*j*j) == f.end()) continue;

			ans += a * f[a*j] * f[a*j*j];
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
