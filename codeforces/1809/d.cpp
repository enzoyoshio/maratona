#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve() {
	string s; cin >> s;
	int n = s.size();
	string sorted;
	sorted = s;
	sort(sorted.begin(), sorted.end());

	if(s == sorted) {
		cout << 0 << endl;
		return;
	}

	vector<int> one(s.size()), zero(s.size());

	for(int i = 0; i < n; i++) {
		one[i] = s[i] == '1';
		zero[i] = s[i] == '0';

		if(i) {
			one[i] += one[i-1];
			zero[i] += zero[i-1];
		}
	}

	int ans = (int)s.size() * ((int)1e12 + 1);

	for(int i = 0; i + 1 < n; i++) {
		int ones = one[i], zeros = zero.back() - zero[i];

		int cur = 0;
		if(s[i] == '1' && s[i+1] == '0') ones--, zeros--, cur += (int)1e12;

//		cout << i << ' ' << cur << ' ' << ones << ' ' << zeros << endl;
		ans = min(ans, cur + (ones+zeros) * ((int)1e12 + 1));
	}

	ans = min(ans, one.back() * ((int)1e12 + 1));
	ans = min(ans, zero.back() * ((int)1e12 + 1));

	cout << ans << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t=1;
	cin >> t;
	while(t--) solve();
}
