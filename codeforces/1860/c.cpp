#include <bits/stdc++.h>

using namespace std;
#define int long long

struct ST {
	vector<int> st;
	int n;

	ST(int n) : n(n), st(4*n) {}

	int update(int x, int v, int sti, int stl, int str) {
		if(x > str || x < stl) return st[sti];

		if(stl == str) return st[sti] = v;

		int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;
		return st[sti] = max(update(x, v, ste, stl, stm)
			, update(x, v, std, stm+1, str));
	}
	int update(int x, int v) { return update(x, v, 1, 0, n-1);}

	int query(int a, int b, int sti, int stl, int str) {
		if(a > b) return 0;
		if(a > str || b < stl) return 0;

		if(a <= stl && str <= b) return st[sti];

		int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;
		return st[sti] = max(query(a, b, ste, stl, stm)
			, query(a, b, std, stm+1, str));
	}
	int query(int a, int b) { return query(a, b, 1, 0, n-1);}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n; cin >> n;
		vector<int> v(n);
		for(auto& it: v) cin >> it, it--;

		vector<int> dp(n);
		ST st(n);
		for(int i = 0; i < n; i++) {
			dp[i] = st.query(0, v[i]-1) + 1;
			st.update(v[i], dp[i]);
		}

		int ans = 0;
		for(auto it: dp) ans += it == 2;
		cout << ans << '\n';
	}
}
