#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> v(m);
	for(auto& [a, b]: v) cin >> b >> a;
	sort(begin(v), end(v));

	int g = n;
	for(auto [a, b]: v) g = gcd(g, b);

	if(g != 1) return cout << -1 << endl, 0;

	int ans = 0;
	int cc = n;

	for(auto [a, b]: v) {

		if(cc == 1) break;
		ans += a * (cc/gcd(cc, b) -1) * gcd(cc, b); 
		cc = gcd(cc, b);
	}
	cout << ans << endl;
}
