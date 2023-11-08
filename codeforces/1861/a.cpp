#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAXN = 1e5;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	vector<int> p;
	bitset<MAXN> a;
	a.set();
	for(int i = 2; i < MAXN; i++) {
		if(a[i]) {
			if(to_string(i).size() > 1)
				p.push_back(i);
			for(int j = i+i; j < MAXN; j += i)
				a[j] = 0;
		}
	}
	int t; cin >> t; while(t--) {
		string s;
		cin >> s;

		int ans = -1;
		for(auto it: p) {

			string t = to_string(it);

			int idx = 0;

			for(auto el: s) {
				if(idx < t.size() &&
				   t[idx] == el) idx++;
			}

			if(idx == t.size()) {
				ans = it;
				break;
			}
		}
		cout << ans << endl;

	}
}
