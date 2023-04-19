#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n, l, r;
		cin >> n >> l >> r;

		bool can = 1;
		vector<int> ans;
		for(int i = 1; i <= n; i++) {
			int x = (l + i -1)/i * i;

			if(x > r)
				can = 0;
			ans.push_back(x);
		}

		if(!can) {
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
		for(auto it: ans)
			cout << it << ' ';
		cout << endl;
	}
}
