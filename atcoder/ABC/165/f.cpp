#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"

int n;
vector<vector<int>> arv;
vector<int> cost, ans, ord;

struct ST {
	vector<int> st;
	int n;

	ST() {}

	ST(int _n): n(_n) {
		st.resize(4*n);
	}

	int update(int id, int x, int sti, int stl, int str) {
		if(stl > id || id > str) return st[sti];

		if(stl == str) return st[sti] = x;

		int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;
		return st[sti] = max(update(id, x, ste, stl, stm), update(id, x, std, stm+1, str));
	}
	int  update(int id, int x) { return update(id, x, 1, 0, n-1);}

	int query(int L, int R, int sti, int stl, int str) {
		if(R < L) return 0;
		if(L > str || stl > R) return 0;

		if(L <= stl && str <= R) return st[sti];

		int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;
		return max(query(L, R, ste, stl, stm), query(L, R, std, stm+1, str));
	}
	int query(int L, int R) { return query(L, R, 1, 0, n-1);}
};

ST st;

void dfs(int u=0, int p=0) {
//	cout << u << ' ' << p << endl;

//	db(cost[u]);
	int last = st.query(cost[u], cost[u]);
//	cout << "after last\n";

	int novo = st.query(0, cost[u]-1) + 1;
//	cout << "after query\n";
	st.update(cost[u], max(novo, last));
	ans[u] = st.query(0, n-1);

//	cout << "cheguei aqui after update\n";

	for(auto v: arv[u]) if(v != p) {
		dfs(v, u);
	}
	st.update(cost[u], last);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n;
	cost.resize(n);
	arv.resize(n);
	ans.resize(n);
	for(auto& it: cost) cin >> it;
	ord = cost;
	sort(begin(ord), end(ord));

	for(auto& it: cost) it = lower_bound(begin(ord), end(ord), it) - begin(ord);

	for(int i = 1; i < n; i++) {
		int a, b; cin >> a >> b; a--, b--;
		arv[a].push_back(b);
		arv[b].push_back(a);
	}

	st = ST(n);

	dfs();
	for(auto it: ans) cout << it << '\n';
}
