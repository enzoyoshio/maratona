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

#define double long double
const double EPS = 1e-12;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cout << fixed << setprecision(12);

	int n, m, x;
	cin >> n >> m >> x;

	Dinitz d(n, 0, n-1);

	for(int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c; a--, b--;

		d.add_edge(a, b, c);
	}

	int f = d.flow();

	vector<int> flows;
	for(auto [v, u, cap, flow]: d.edges)
		if(u == n-1)
			flows.push_back(flow);

	int l = 1, r = accumulate(begin(flows), end(flows), 0LL), ans = 0;

	/*
	while(l <= r) {
		int mid = (l+r) >> 1;

		int qt = 0;
		for(auto el: flows)
			qt += el/mid;

		if(qt >= x) ans = mid, l = mid+1;
		else r = mid-1;
	}

	if(ans)
		for(auto& it: flows)
			it %= ans;
	*/

	for(auto it: flows)
		cout << it << ' ';
	cout << endl;

	sort(rbegin(flows), rend(flows));
	while(flows.size() && !flows.back()) flows.pop_back();
	double ldouble = 0.000000001, rdouble = flows.back(), 
	       ansdouble = 0;
	
	rdouble = accumulate(begin(flows), end(flows), 0LL);

	while(fabs(rdouble-ldouble) > EPS) {
		cout << "\n\n------------------------------------------->\n";
		cout << ldouble << ' ' << rdouble << endl;
		double mid = (rdouble+ldouble)/2;
		cout << "mid = " << mid << endl;

		int qt = 0;
		cout << "elementos\n";
		for(auto el: flows) {
			cout << floor(el/mid) << ' ';
			qt += floor((double)el/mid);
		}
		cout << endl;

		cout << "qt = " << qt << endl;
		if(qt >= x) ansdouble = mid, ldouble = mid;
		else rdouble = mid;
	}

	cout << ansdouble << endl;
	cout << x*(ansdouble) << endl;
}
