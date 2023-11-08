#include <bits/stdc++.h>

using namespace std;
#define int long long

int sum(int x) {
	return x*(x+1)/2;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n, a, b, c, x, y;
		cin >> n >> x >> y;
		a = n/x;
		b = n/lcm(x, y);
		c = n/y;

		cout << sum(n) - sum(n-a+b) - sum(c-b) << '\n';
	}
}
