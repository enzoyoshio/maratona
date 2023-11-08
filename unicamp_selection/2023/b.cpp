#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t=1;
	while(t--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int ans = 0;

		while(x1 <= x2 && ans < (int)1e6) {
			ans++;
			x1 += y1;
			x2 += y2;
		}

		if(ans == (int)1e6) cout << -1 << endl;
		else cout << ans << endl;
	}
}
