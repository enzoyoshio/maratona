#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for(auto& it: v) cin >> it, it--;

	vector<int> a(n), b(n), need(n);

	int cur = 5e8;
	for(auto it: v) need[it] = cur++;

	a[0] = 1;
	b[0] = need[0] - 1;

	a.back() = need.back() - 1;
	b.back() = 1;

	for(int i = 1; i+1 < n; i++) {
		int na = need[i] - (b[i-1]-1);

		if(na > a[i-1]) {
			b[i] = b[i-1] -1;
			a[i] = na;
		}else {
			b[i] = need[i] - (a[i-1]+1);
			a[i] = a[i-1] + 1;
		}
	}

	for(auto el: a) cout << el << ' '; cout << endl;
	for(auto el: b) cout << el << ' '; cout << endl;
}
