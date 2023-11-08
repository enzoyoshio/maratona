#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int a, b, c; cin >> a >> b >> c;

		if(a >= b+c) {
			cout << "First\n";
			continue;
		}
		if(b > a+c) {
			cout << "Second\n";
			continue;
		}

		if(c%2) {
			if(b > a) cout << "Second\n";
			else cout << "First\n";
		}else {
			if(a > b) cout << "First\n";
			else cout << "Second\n";
		}
	}
}
