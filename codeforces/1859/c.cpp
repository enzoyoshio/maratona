#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n; cin >> n;
		if(n == 2) {
			cout << 2 << '\n';
			continue;
		}

		int ans = 0, m = 0;
		for(int i = 1; i <= n; i++)
			ans += i*(n-i+1), m = max(m, i*(n-i+1));
		ans -= m;

		int acum = 0;
		for(int i = 1; i <= n; i++) {
			acum += i*i;

			int maxi = i*i;
			int cur = acum;
			for(int j = i+1, other = n; j <= n; j++, other--)
				cur += j * other, maxi = max(maxi, j*other);

//			cout << cur << ' ' << maxi << endl;
			ans = max(ans, cur-maxi);

		}
		cout << ans << '\n';
	}
}
