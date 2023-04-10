#include <bits/stdc++.h>

using namespace std;

#define int long long

int solve() {
	int n; cin >> n;
	vector<int> v(n);
	for(auto& it: v)
		cin >> it;

	if(n == 2) {
		if(v[0] <= v.back()) cout << "yes";
		else cout << "no";
		cout << '\n';
		return 0;
	}

	if(n%2)
		return cout << "yes\n", 0;

	for(int i = n-3; i >= 0; i--) {
		int dif = v[i+2]-v[i+1];
		v[i+1] += dif;
		v[i] += dif;
	}

	for(int i = 0; i+1 < n; i++)
		if(v[i] > v[i+1])
			return cout << "no\n", 0;

	cout << "yes\n";

	return 0;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t=1;
	cin >> t;
	while(t--) solve();
}
