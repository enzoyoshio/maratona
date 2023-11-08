#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e18;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t;

	for(int i = 1; i <= t; i++) {

		int n; cin >> n;
		vector<int> v(n);
		for(auto& it: v) cin >> it;
		sort(begin(v), end(v));

		int ans = 0;

		if(n%2 == 0) {
			ans = (v.back() + v[n-2]) - (v[0] + v[1]);
		}else {
			ans = max(ans, 
					(v.back() + v[n-2])
					-(v[0] + v[2]));
			ans = max(ans,
					(v.back() + v[n-3])
					-(v[0] + v[1]));
			if(n > 5) {
				ans = max(ans, 
				(v.back() + v[n-2]) - (v[0] + v[1]));
			}
		}

		cout << fixed << setprecision(18);
		cout << "Case #" << i << ": " << ans/2.0 << '\n';
	}
}
