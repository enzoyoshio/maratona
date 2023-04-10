#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(auto& it: a)
		cin >> it;
	for(auto& it: b)
		cin >> it;

	for(int i = 0; i < n; i++) {
		if(a[i] < b[i]) swap(a[i], b[i]);
	}

	if(*max_element(a.begin(), a.end()) == a.back() && *max_element(b.begin(), b.end()) == b.back()) cout << "yes\n";
	else cout << "no\n";
	
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t = 1;
	cin >> t;
	while(t--) solve();
}
