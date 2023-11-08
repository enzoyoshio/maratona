#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(auto& it: a) cin >> it;
	for(auto& it: b) cin >> it;

	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] > b[i]) return cout << -1 << endl, 0;
		ans += b[i]-a[i];

	}

	cout << ans << endl;
}
