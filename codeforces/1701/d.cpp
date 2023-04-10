#include <bits/stdc++.h>

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for(auto& it: v) cin >> it;

		vector<tuple<int,int,int>> ranges;
		vector<int> ans(n);
		for(int i = 0; i < n; i++) {
			int l = (i+1)/(v[i]+1)+1;
			int r = (!v[i] ? n :(i+1)/v[i]);
			if(l > r) l = r;
			ranges.emplace_back(l, r, i);
		}

		sort(ranges.begin(), ranges.end());
		int cur = 0;
		set<pair<int,int>> ends;

		/*
		cout << "ranges\n";
		for(auto [l, r, idx]: ranges) {
			db(l);
			db(r);
			db(idx+1);
		}
		*/

//		cout << "\n\n\ndoing\n";
		for(int i = 1; i <= n; i++) {
			while(cur < ranges.size() && get<0>(ranges[cur]) <= i) {
				ends.emplace(get<1>(ranges[cur]), get<2>(ranges[cur]));
				cur++;	
			}

			auto [val, idx] = *ends.begin();
		//	db(val);
		//	db(idx+1);
			ends.erase(ends.begin());

			ans[idx] = i;

		}

		for(auto el: ans)
			cout << el << ' ';
		cout << endl;
	}
}
