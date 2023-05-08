#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	int n, t;
	cin >> n >> t;
	vector<int> a(n), b(n);
	for(auto& it: a)
		cin >> it;
	for(auto& it: b)
		cin >> it;

	int ans = -2;

	for(int i = 0; i < n; i++) {
		if(t-i >= a[i] && (ans == -2 || b[ans] < b[i]))
			ans = i;
	}
	cout << ans+1 << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t=1;
	cin >> t;
	while(t--) solve();
}
