#include <bits/stdc++.h>

using namespace std;
#define int long long

using iii = array<int,3>;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n, m, d; cin >> n >> m >> d;
		vector<int> v(n);
		for(auto& it: v) cin >> it;

		set<iii> s;
		s.insert({0, 0, 0});

		int ans = 0;
		for(int i = 0; i < n; i++) {
			auto [a, b, c] = *rbegin(s);

			ans = max(ans, a - (i+1-b)*d + v[i]);
			ans = max(ans, v[i] - d*(i+1));

			s.insert({v[i] - d*(i+1), i+1, 1});
			if(c+1 < m) {
				s.insert({
					a-(i+1-b)*d+v[i],
					i+1,
					c+1
						});
			}

			auto p = s.lower_bound({a, 0, 0});

			if(p == end(s)) continue;

			auto [a1, b1, c1] = *p;

			ans = max(ans, a1 - (i+1-b1)*d + v[i]);
			ans = max(ans, v[i] - d*(i+1));

			if(c1+1 < m) {
				s.insert({
					a1-(i+1-b1)*d+v[i],
					i+1,
					c1+1
						});
			}

		}
		cout << " ans = " <<  ans << endl;
	}
}
