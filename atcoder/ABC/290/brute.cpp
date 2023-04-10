#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for(auto& it: v)
		cin >> it;

	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			if(v[i] == v[j]) continue;
			ans += min(i+1, n-j);
		}
	}
	cout << ans << endl;
}
