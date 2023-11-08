#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int a, b, n;
		cin >> a >> b >> n;
		vector<int> v(n);
		for(auto& it: v) cin >> it, it = min(a, it);
		int ans = 0;
		for(auto it: v) {
			if(1 + it <= a) ans += it;
			else ans += a-1;
		}
		ans++;
		ans += b-1;
		cout << ans << endl;
		
	}
}
