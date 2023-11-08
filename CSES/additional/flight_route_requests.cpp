#include <bits/stdc++.h>

using namespace std;
#define int long long

struct DSU {
	vector<int> pai, vis, tam;
	vector<vector<int>> ans;
	int n;

	DSU(int _n) : n(_n),
		      pai(_n),
		      vis(_n),
		      ans(_n, vector<int>()), 
		      tam(_n, 1) 
		      {
		iota(begin(pai), end(pai), 0LL);
	}

	int find(int x) { return x == pai[x] ? x : pai[x] = find(pai[x]);}

	void join(int x, int y) {
		x = find(x);
		y = find(y);

		if(x == y) return;

		if(tam[x] < tam[y]) swap(x, y);
		pai[y] = x;
		tam[x] += tam[y];
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector g(n, vector<int>());

	DSU d(n);

	vector<int> in(n);
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--, b--;
		in[b]++;
		g[a].push_back(b);
		d.join(a, b);
	}

	queue<int> q;
	vector<int> vis(n);
	for(int i = 0; i < n; i++) {
		if(!in[i]) q.push(i);
	}

	while(q.size()) {
		auto u = q.front(); q.pop();

		vis[u] = true;
		d.ans[d.find(u)].push_back(u);
		d.vis[d.find(u)]++;

		for(auto v: g[u]) {
			in[v]--;

			if(!in[v]) {
				q.push(v);
				vis[v] = true;
			}
		}
	}

	for(int i = 0; i < n; i++)
		if(!vis[i]) d.ans[d.find(i)].push_back(i);

	int conta = 0;
	for(int i = 0; i < n; i++) {
		if(i != d.find(i)) continue;

		conta += (int)d.ans[i].size() -1;

		if(d.tam[i] != d.vis[i]) {
			conta++;
		}
	}

	cout << conta << endl;
}
