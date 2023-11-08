#include <bits/stdc++.h>

using namespace std;
#define int long long

struct ST {
	vector<int> st0, st1, lazy;
	int n;

	ST(int n) : n(n), st0(4*n), st1(4*n), lazy(4*n) {}

	void prop(int sti, int stl, int str) {
		if(lazy[sti]) {

			if(lazy[sti]%2)
				swap(st0[sti], st1[sti]);

			if(stl != str) {
				lazy[2*sti] += lazy[sti];
				lazy[2*sti+1] += lazy[sti];
			}

			lazy[sti] = 0;
		}
	}

	void update(int pos, int x, int b, int sti, int stl, int str) {
		prop(sti, stl, str);
		if(pos > str || pos < stl) return;

		if(stl == str) {
			if(b) st1[sti] = x;
			else st0[sti] = x;
			return;
		}

		int stm = (stl+str)/2, ste = (2*sti), std = 2*sti+1;

		update(pos, x, b, ste, stl, stm);
		update(pos, x, b, std, stm+1, str);
		st0[sti] = st0[ste] ^ st0[std];
		st1[sti] = st1[ste] ^ st1[std];
	}
	void update(int pos, int x, int b) {
		update(pos, x, b, 1, 0, n-1);
	}

	void flip(int A, int B, int sti, int stl, int str) {
		prop(sti, stl, str);

		if(A > str || stl > B) return;

		if(A <= stl && str <= B) {
			lazy[sti]++;
			prop(sti, stl, str);
			return;
		}

		int stm = (stl+str)/2, ste = (2*sti), std = 2*sti+1;

		flip(A, B, ste, stl, stm);
		flip(A, B, std, stm+1, str);
		st0[sti] = st0[ste] ^ st0[std];
		st1[sti] = st1[ste] ^ st1[std];
	}
	void flip(int A, int B) {
		flip(A, B, 1, 0, n-1);
	}

	pair<int,int> merge(pair<int,int> a, pair<int,int> b) {
		a.first ^= b.first;
		a.second ^= b.second;
		return a;
	}

	pair<int,int> query(int A, int B, int sti, int stl, int str) {
		prop(sti, stl, str);

		if(A > str || stl > B) return {0, 0};

		if(A <= stl && str <= B) {
			return {st0[sti], st1[sti]};
		}

		int stm = (stl+str)/2, ste = (2*sti), std = 2*sti+1;

		return merge(query(A, B, ste, stl, stm),
			     query(A, B, std, stm+1, str));
	}
	pair<int,int> query(int A, int B) {
		return query(A, B, 1, 0, n-1);
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		string s;
		for(auto &it: v) cin >> it;
		cin >> s;

		ST st(n);
		for(int i = 0; i < n; i++) {
			st.update(i, v[i], s[i]-'0');
		}

		int q; cin >> q;
		while(q--) {
			int qt; cin >> qt;

			/*
			auto [a1, b1] = st.query(0, n-1);
			cout << "dbg " << a1 << ' ' << b1 << '\n';
			*/

			if(qt == 2) {
				int b; cin >> b;
				auto [l, r] = st.query(0, n-1);
				if(b) cout << r << ' ';
				else cout << l << ' ';
			}else {
				int l, r; cin >> l >> r;
				l--, r--;
				st.flip(l, r);
			}
		}
		cout << '\n';
	}
}
