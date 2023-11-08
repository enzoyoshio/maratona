#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for(auto& it: v) cin >> it;

		int allAnd = v[0];
		for(auto el: v) allAnd &= el;

		if(allAnd) {
			cout << 1 << '\n';
			continue;
		}

		allAnd = 0;
		int ans = 0;
		for(int i = 0; i < n; i++) {

			if(!allAnd) {
				ans++;
				allAnd = v[i];
			}else {
				allAnd &= v[i];
			}
		}

		if(allAnd) ans--;
		
		/*
		int cur = 0;
		allAnd = 0;
		reverse(begin(v), end(v));

		for(int i = 0; i < n; i++) {
			allAnd &= v[i];

			if(!allAnd) {
				cur++;
				allAnd = v[i];
			}else {
				allAnd &= v[i];
			}
		}

		if(allAnd) cur--;
		ans = max(ans, cur);
		*/

		cout << ans << '\n';
	}
}
