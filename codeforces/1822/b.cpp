#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for(auto& it: v)
		cin >> it;
	sort(begin(v), end(v));

	cout << max(v[0]*v[1], v.back()*v[n-2]) << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t=1;
	cin >> t;
	while(t--) solve();
}
