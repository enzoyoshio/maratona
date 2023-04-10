#include <bits/stdc++.h>

using namespace std;

#define int long long

int solve() {
	int a, b; cin >> a >> b;

	if(a == 1) {
		cout << 1 << endl;
		cout << a << ' ' << b << endl;
	}else {
		cout << 2 << endl;
		cout << a-1 << ' ' << 1 << endl;
		cout << a << ' ' << b << endl;
	}
	return 0;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t=1;
	cin >> t;
	while(t--) solve();
}
