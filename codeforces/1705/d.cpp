#include <bits/stdc++.h>

using namespace std;

#define int long long

const int oo = 1e18;
const int MAXN = 2e5 + 98;
int n; string s, t;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int test; cin >> test; while(test--) {
		cin >> n >> s >> t;

		if(s[0] != t[0] || s.back() != t.back()) {
			cout << -1 << endl;
			continue;
		}

		vector<int> xors(n-1), xort(n-1);
		for(int i = 0; i+1 < n; i++)
			xors[i] = (s[i]-'0') ^ (s[i+1]-'0'),
			xort[i] = (t[i]-'0') ^ (t[i+1]-'0');

		vector<int> bits, bitt;
		for(int i = 0; i < n-1; i++) {
			if(xors[i]) bits.push_back(i);
			if(xort[i]) bitt.push_back(i);
		}

		if(bits.size() != bitt.size()) {
			cout << -1 << endl;
			continue;
		}

		int ans = 0;
		for(int i = 0; i < (int)bits.size(); i++)
			ans += abs(bits[i]-bitt[i]);

		cout << ans << endl;
	}
}
