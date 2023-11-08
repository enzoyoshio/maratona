#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	int t; cin >> t; while(t--) {
		int n; cin >> n;
		vector<int> v(n);
		for(auto& it: v) cin >> it;

		vector<int> ans(n);

		if(v.front() == 1) ans.front() = 2;
		else ans.front() = 1;

		for(int i = 1; i < n; i++) {
			if(ans[i-1]+1 != v[i]) ans[i] = ans[i-1]+1;
			else {
				ans[i] = v[i]+1;
			}
		}
		cout << ans.back() << endl;
	}
}
