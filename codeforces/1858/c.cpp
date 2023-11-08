#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n; cin >> n;

		vector<bool> used(n+10);
		vector<int> ans;
		ans.push_back(1);

		// can I make gcd(a, b) = i ?
		for(int i = 2; i <= n; i++) {
			if(!used[i]) {
				for(int j = i; j <= n; j *= 2) {
					if(!used[j]) {
						ans.push_back(j);
						used[j] = true;
					}
				}
			}	
		}

		for(auto el: ans) cout << el << ' ';
		cout << '\n';

	}
}
