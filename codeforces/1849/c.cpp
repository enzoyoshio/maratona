#include <bits/stdc++.h>

using namespace std;
#define int long long

struct ST {

	vector<int> st;
	int n;

	ST(int n) : n(n) {
		st.resize(4*n);
	}

	int update(int l, int r, int sti, int stl, int str) {

		if(l > 
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n, m;
		cin >> n >> m;
		string s; cin >> s;

		vector<int> ones(n);

		for(int i = 0; i < n; i++) {
			ones[i] = s[i] == '1';
			if(i) ones[i] += ones[i-1];
		}

		/*
		for(int i = 0; i < 3; i++)
			cout << h.query(0, n-1)[i] << ' ' ; cout << endl;
			*/

		vector<pair<int,int>> vp(m);
		for(int i = 0; i < m; i++) {
			int l, r; cin >> l >> r;
			l--, r--;
			vp[i] = {l, -r};
		}
		sort(begin(vp), end(vp));

		for(int i = 0; i < m; i++) {
			int l = vp[i].second, r = n-1, ans = vp[i].second;
			while(l <= r) {
				int mid = (l+r)/2;
				if(ones[mid] - (vp[i].second ? ones[vp[i].second-1] : 0) == mid-vp[i].second+1) ans = mid, l = mid+1;
				else r = mid-1;
			}
			st.update(vp[i].second, vp[i].second + ans, 0);
			st.update(vp[i].first, vp[i].first, st.query(vp[i].first, vp[i].first)+1);
		}

		cout << st.query(0, n-1) << '\n';
	}
}
