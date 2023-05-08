#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	int n;
	string s;
	cin >> n >> s;

	if(n%2) {
		cout << -1 << endl;
		return;
	}

	vector<int> f(26, 0);

	for(auto ch: s)
		f[ch-'a']++;

	if(*max_element(begin(f), end(f)) > n/2) {
		cout << -1 << endl;
		return;
	}
	
	vector<int> equal(26, 0);
	for(int i = 0; i < n/2; i++) {
		if(s[i] == s[n-i-1]) {
			equal[s[i]-'a']++;
		}
	}

	sort(rbegin(equal), rend(equal));
	int ans = 0;

	int total = accumulate(begin(equal), end(equal), 0LL);

	if(*equal.begin() > total/2) cout << *equal.begin() << endl;
	else cout << (total+1)/2 << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t=1;
	cin >> t;
	while(t--) solve();
}
