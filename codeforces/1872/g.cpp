#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n, has1 = 0;
		cin >> n;
		vector<int> v(n);
		for(auto& it: v) cin >> it, has1 |= it == 1;

		if(!has1 || n == 1) {
			cout << 1 << ' ' << n << '\n';
			continue;
		}



	}
}
