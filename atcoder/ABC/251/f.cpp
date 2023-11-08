#include <bits/stdc++.h>

using namespace std;
#define int long long

using ii = pair<int,int>;

int n, m;
vector<vector<int>> g;
vector<int> h;
vector<ii> t1, t2;

void dfs(int u=0, int p=0) {
	h[u] = h[p]+1;
	for(auto v: g[u]) if(v != p && h[v] == -1) {
		dfs(v, u);
		t1.emplace_back(u, v);
	}
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m;
	g.resize(n);
	h.resize(n, -1);

	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs();
	for(int i = 0; i < n; i++) h[i] = 0;
	queue<int> q;
	q.push(0);
	h[0] = 1;

	while(q.size()) {
		auto u = q.front(); q.pop();

		for(auto v: g[u]) if(!h[v]) {
			t2.emplace_back(u, v);
			q.push(v);
			h[v] = 1;
		}
	}

	for(auto [a, b]: t1) cout << a+1 << ' ' << b+1 << '\n';
	for(auto [a, b]: t2) cout << a+1 << ' ' << b+1 << '\n';
}
