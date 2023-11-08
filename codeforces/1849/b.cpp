#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n, k;
		cin >> n >> k;
		vector<int> v(n), ans;
		for(auto& it: v) cin >> it;

		map<int, vector<int>> m;
		for(int i = 0; i < n; i++) {
			int it = v[i];
			m[(it%k == 0 ? k : it%k)].push_back(i);
		}

		for(auto it = rbegin(m); it != rend(m); it++) {
			for(auto ii: it->second)
				cout << ii+1 << ' ';
		}
		cout << '\n';
	}
}
