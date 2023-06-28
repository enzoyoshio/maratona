#include <bits/stdc++.h>

using namespace std;

#define int long long

bool check(int know, int cur) {
	int opose = ~know;
	return !(opose & cur);
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n, x;
		cin >> n >> x;
		vector v(3, vector<int>(n));
		for(auto& line: v)
			for(auto& it: line)
				cin >> it;

		int knowledge = 0;
		for(int i = 0; i < 3; i++) {
			for(auto el: v[i]) {
				if(!check(x, knowledge | el)) break;
				knowledge |= el;
			}
		}

		cout << (knowledge == x ? "Yes" : "No") << '\n';
	}
}
