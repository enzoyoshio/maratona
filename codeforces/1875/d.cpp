#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e18;
const int MAX = 5e3 + 8;

using ii = pair<int,int>;

struct ST {
	// min el/ idx
	vector<pair<int,int>> st;
	int n;
	ii neutro = {oo, -oo};

	ST(int n) : n(n), st(4*n, {0, -1}) {
		
	}

	ii f(ii a, ii b) {
		if(a.first <= b.first) {
			return a;
		}else
			return b;
	}

	ii update(int id, int x, int sti, int stl, int str) {
		if(id > str || id < stl) return st[sti];

		if(stl == str) {
			st[sti].first += x;
			st[sti].second = id;
			return st[sti];
		}

		int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;
		return st[sti] = f(update(id, x, ste, stl, stm),
				   update(id, x, std, stm+1, str));
	}
	ii update(int id, int x) { return update(id, x, 1, 0, n-1);}

	ii query(int L, int R, int sti, int stl, int str) {
		if(L > str || stl > R) return neutro;

		if(L <= stl && str <= R) return st[sti];

		int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;
		return f(query(L, R, ste, stl, stm), 
			 query(L, R, std, stm+1, str));
	}
	ii query(int L, int R) { return query(L, R, 1, 0, n-1);}
};

int testa(vector<int>& f, int lim) {

	if(f[0] == 0) return 0;

	int cur = oo;
	for(int i = 0; i < lim; i++) {
		auto qt = f[i];

		f[i] = 0;

		cur = min(cur,
			  (qt + (i == 0 ? 0 : -1)) * lim + testa(f, i));
		cout << "lim " << lim << endl;
		cout << "i " << i << endl;
		cout << "cur " << cur << endl;
		f[i] = qt;
	}

	return cur;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		vector<int> f(MAX);
		for(auto& it: v) cin >> it;
		sort(begin(v), end(v));
		if(v.front()) {
			cout << 0 << '\n';
			continue;
		}

		ST st(MAX);
		for(int i = 0; i < MAX; i++)
			st.update(i, 0);

		for(int i = 0; i < n; i++) {
			if(v[i] >= MAX) continue;
			st.update(v[i], 1);
			f[v[i]]++;
		}

		int lim = st.query(0, MAX-1).second;
		cout << testa(f, lim) << '\n';
		continue;
		/*
		for(int i = 0; i < lim; i++) {
			ST st2 = st;

			int cur = 0;
			
			int idx = i;
			while(st2.query(0, MAX-1).second) {
				st2.update(idx, -1);
				auto q = st2.query(0, MAX-1);
				cur += q.second;
				if(q.second == idx) idx = st2.query(0, idx-1).second;
			}

			ans = min(ans, cur);
		}

		for(int i = 0; i < lim; i++) {
			ST st2 = st;
			int cur = 0;
			for(int j = i; j >= 0; j--) {
				while(st2.query(j, j).first) {
					st2.update(j, -1);
					cur += st2.query(0, MAX-1).second;
				}
			}
		}

		cout << ans << '\n';
		*/
	}
}
