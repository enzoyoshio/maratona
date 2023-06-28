#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n, m;
		cin >> n >> m;
		vector<int> v(n), u(m);
		for(auto& it: v) cin >> it;
		for(auto& it: u) cin >> it;

		int first = accumulate(begin(v), end(v), 0LL);
		int second = accumulate(begin(u), end(u), 0LL);

		if(first > second) cout << "Tsondu\n";
		else if(second > first) cout << "Tenzing\n";
		else cout << "Draw\n";
	}
}
