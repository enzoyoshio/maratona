#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	string s;
	string t;
	cin >> s >> t;

	vector<int> pos[26];
	for(int i = 0; i < (int)s.size(); i++)
		pos[s[i]-'a'].push_back(i);

	int cur = -1;

	for(auto ch: t) {
		
		if(pos[ch-'a'].empty())
			return cout << -1 << endl, 0;

		int line = cur%(int)s.size();

		auto p = upper_bound(pos[ch-'a'].begin(), pos[ch-'a'].end(), line);

		if(p == pos[ch-'a'].end()) {
			cur += pos[ch-'a'][0] + (int)s.size() - line;
		}else cur += (*p)-line;

	}

	cout << cur + 1 << endl;
}
