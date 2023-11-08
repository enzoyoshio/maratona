#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n, m;
		cin >> n >> m;
		if(n%m == 0) {
			cout << 0 << '\n';
			continue;
		}

		int g = gcd(n, m);
		int on = n, om = m;
		n /= g;
		m /= g;
		if(__builtin_popcountll(m) > 1) {
			cout << -1 << '\n';
			continue;
		}

		n %= m;
		int ans = 0;

		for(int i = 2; i <= m; i *= 2) {
			if(n*i < m) continue;

			ans += (i-1) * (m/i);
			n -= m/i;
		}

		cout << ans * (om/m) << '\n';

	}
}
