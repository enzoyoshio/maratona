#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n, c, q;
		cin >> n >> c >> q;

		string s;
		cin >> s;
		vector<pair<int,int>> appended(c);
		vector<int> starting(c);
		for(auto& [l, r]: appended)
			cin >> l >> r, l--, r--;

		starting[0] = (int)s.size();
		for(int i = 1; i < c; i++)
			starting[i] = starting[i-1] + appended[i-1].second - appended[i-1].first + 1;

		while(q--) {
			int k; cin >> k;
			k--;

			int idx = c-1;

			while(idx >= 0) {
				if(starting[idx] <= k) {
					k = k-starting[idx] + appended[idx].first;
				}
				idx--;
			}


			
			//cout << k << ' ' << idx << endl;
			cout << s[k] << endl;
		}
	}
}
