#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 8;

struct Dinitz {
	struct Edge {
		int v, u, cap, flow=0;
		Edge(int v, int u, int cap) : v(v), u(u), cap(cap) {}
	};

	vector<Edge> edges;
	vector<vector<int>> adj;

	int n, s, t;
	Dinitz(int n, int s, int t) : n(n), s(s), t(t) {
		adj.resize(n);
	}

	void add_edge(int v, int u, int cap) {
		edges.emplace_back(v, u, cap);
		adj[v].push_back((int)edges.size()-1);
		edges.emplace_back(u, v, 0);
		adj[u].push_back((int)edges.size()-1);
	}

	vector<int> level;
	bool bfs() {
		queue<int> Q;
		level.assign(n, -1);
		level[s] = 0;
		Q.push(s);

		while(!Q.empty()) {
			int v = Q.front(); Q.pop();
			for(auto eid: adj[v]) {
				auto e = edges[eid];
				if(e.cap-e.flow <= 0) continue;
				if(~level[e.u]) continue;

				level[e.u] = level[v] + 1;
				Q.push(e.u);
			}
		}
		return level[t] != -1;
	}

	vector<int> ptr;
	int dfs(int v, int f) {
		if(f == 0 || v == t) return f;
		for(int &cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
			int eid = adj[v][cid];
			auto &e = edges[eid];
			if(e.cap - e.flow <= 0) continue;
			if(level[e.u] != level[e.v] + 1) continue;
			int newf = dfs(e.u, min(f, e.cap-e.flow));
			if(!newf) continue;

			e.flow += newf;
			edges[eid^1].flow -= newf;
			return newf;
		}
		return 0;
	}

	int flow() {
		int f = 0;
		while(bfs()) {
			ptr.assign(n, 0);
			while(int newf = dfs(s, INF))
				f += newf;
		}
		return f;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n);
	for(auto& it: a)
		cin >> it;
	for(auto& it: b)
		cin >> it;

	int s = 2*n+1, t = 2*n+2;
	Dinitz d(2*n+8, s, t);

	for(int i = 0; i < m; i++) {
		int p, q; cin >> p >> q;
		p--, q--;
		d.add_edge(p, q+n, a[p]);
		d.add_edge(q, p+n, a[q]);
	}

	for(int i = 0; i < n; i++) {
		d.add_edge(s, i, a[i]);
		d.add_edge(i+n, t, b[i]);
		d.add_edge(i, i+n, a[i]);
	}

	int f = d.flow();

	int acumB = accumulate(begin(b), end(b), 0LL), acumA = accumulate(begin(a), end(a), 0LL);
	if(f != acumB || acumB != acumA)
		return cout << "NO\n", 0;

	vector<vector<int>> ans(n, vector<int>(n,0));

	for(auto [v, u, cap, fl]: d.edges) {
		if(v == s || v == t || u == s || u == t) continue;
		if(fl <= 0) continue;

		ans[v][u%n] = fl;
	}

	cout << "YES\n";
	for(auto line: ans) {
		for(auto el: line)
			cout << el << ' ';
		cout << endl;
	}
}
