#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << (abs(a-b)+2*c-1)/(2*c) << '\n';
	}
}
