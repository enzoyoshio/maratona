#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int b, c, h;

		cin >> b >> c >> h;
		int ans = 1;
		b--;

		while(b && (c || h)) {
			ans += 2;
			b--;
			if(c) c--;
			else h--;
		}
		cout << ans << endl;
		
	}
}
