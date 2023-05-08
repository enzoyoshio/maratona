#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	int n;
	cin >> n;

	if(n == 4) {
		cout << 26 << endl;
		return;
	}

	n *= 2;
	n++;

	int h = (n+1)/2;

	cout << 26 + 2*(h*(h+1)/2) - h - 1 - 3 - 5 - 7 - 9 << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t=1;
	cin >> t;
	while(t--) solve();
}
