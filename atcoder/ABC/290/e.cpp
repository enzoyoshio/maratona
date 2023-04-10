#include <bits/stdc++.h>

#define int long long

using namespace std;

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for(auto& it: v)
		cin >> it, it--;

	vector<vector<int>> each(n);

	int ans = 0;

	auto query = [&](int r, int idx) {
		if(r == 0) return each[v[idx]][r];

		return each[v[idx]][r] - each[v[idx]][r-1];
	};

	for(int i = n-1; i >= 0; i--) {
		int cur = i+1;
		int other = n-i-1;

		if(cur >= other) {
//			db(other);
			ans += other * (other + 1) / 2;
			if(each[v[i]].size()) {
//				db(each[v[i]].back());
//				db(each[v[i]].size());
				ans -= each[v[i]].back();
			}
		}else {

			ans += cur * (cur+1) / 2;

			ans += (other - cur) * cur;
//			db(other);
//			db(cur);


			int l = 0, r = (int)each[v[i]].size() - 1, res = -1;
//			db(l);
//			db(r);

			while(l <= r) {
				int mid = (l + r) >> 1;

//				db(query(mid, i));
				if(query(mid, i) <= cur) res = mid, l = mid+1;
				else r = mid-1;
			}
		
//			db(res);
			if(~res) {
				ans -= each[v[i]][res];
				ans -= cur * ((int)each[v[i]].size() - res - 1);	
			}else if(each[v[i]].size()) {
				ans -= cur * ((int)each[v[i]].size());
			}
		}
//		db(ans);

		each[v[i]].push_back(other+1 + (each[v[i]].size() ? each[v[i]].back() : 0)); 
	}

	cout << ans << endl;

}
