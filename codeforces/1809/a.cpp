#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve() {
 	string s;
	cin >> s;

	sort(s.begin(), s.end());
	if(s[0] == s[3]) {
		cout << -1 << endl;
		return;
	}

	set<char> se;
	for(auto& ch: s) se.insert(ch);

	if(se.size() == 4) {
		cout << 4 << endl;
	}else if(se.size() == 3) {
		cout << 4 << endl;	
	}else if(se.size() == 2) {
		if(s[0] != s[1] || s.back() != s[2]) cout << 6 << endl;
		else cout << 4 << endl;
	}else {
		cout << -1 << endl;
	}
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t=1;
	cin >> t;
	while(t--) solve();
}
