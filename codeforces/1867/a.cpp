#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);
	/*
	vector<int> p = {1, 2, 3, 4};
	vector<int> vv = {1, 2, 4, 3};

	do {
		set<int> c;
		for(int i = 0; i < 4; i++) 		
			c.insert(vv[i] - p[i]);
		if(c.size() == 4) {
			for(auto it: p) cout << it << ' '; cout << endl;
			cout << "cost = " << c.size() << endl;
		}
	}while(next_permutation(begin(p), end(p)));
	return 0;
	*/

	int t; cin >> t; while(t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		vector<pair<int,int>> vp(n);
		for(int i = 0; i < n; i++) {
			cin >> vp[i].first;
			vp[i].second = i;
		}
		vector<int> ans(n);
		sort(rbegin(vp), rend(vp));
		int id = 1;
		for(auto [a, b]: vp) {
			ans[b] = id++;
		}

		for(auto el: ans) cout << el << ' ';
		cout << '\n';


	}
}
