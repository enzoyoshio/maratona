#include <bits/stdc++.h>

using namespace std;

#define int long long
const int oo = 1e11;
const int INF = 1e18;
using iii = array<int, 3>;

struct Dinitz {
	struct Edge {
		int v, u, cap, flow=0;
		Edge (int v, int u, int cap) : v(v), u(u), cap(cap) {}
	};

	vector<Edge> edges;
	vector<vector<int>> adj;

	int n, s, t;
	  Dinitz(int n, int s, int t) : n(n), s(s), t(t) {
		      adj.resize(n);
			}

	    void add_edge(int v, int u, int cap) {
			edges.emplace_back(v, u, cap);
			    adj[v].push_back(edges.size()-1);
				edges.emplace_back(u, v, 0);
				    adj[u].push_back(edges.size()-1);
				      }

	      vector<int> level;
		bool bfs() {
			    queue<int> Q;
				level.assign(n, -1);
				    level[s] = 0;
					Q.push(s);
					    while (!Q.empty()) {
							  int v = Q.front(); Q.pop();
								for (auto eid : adj[v]) {
										auto e = edges[eid];
											if (e.cap - e.flow <= 0) continue;
												if (level[e.u] != -1) continue;
													level[e.u] = level[v] + 1;
														Q.push(e.u);
														      }
								    }
						return level[t] != -1;
						  }

		  vector<int> ptr;
		    int dfs(int v, int f) {
				if (f == 0 || v == t) return f;
				    for (int &cid = ptr[v]; cid < adj[v].size(); cid++) {
						  int eid = adj[v][cid];
							auto &e = edges[eid];
							      if (e.cap - e.flow <= 0) continue;
								    if (level[e.u] != level[e.v] + 1) continue;
									  int newf = dfs(e.u, min(f, e.cap-e.flow));
										if (newf == 0) continue;
										      e.flow += newf;
											    edges[eid^1].flow -= newf;
												  return newf;
												      }
					return 0;
					  }

		      int flow() {
				  int f = 0;
				      while (bfs()) {
						    ptr.assign(n, 0);
							  while (int newf = dfs(s, INF))
									  f += newf;
							      }
					  return f;
					    }
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<iii> v(m);
	int hasN = false;
	for(auto& [a, b, c]: v) {
		cin >> a >> b >> c;
		hasN |= a == n | b == n;
		a--, b--;
	}

	// se nao tiver restricao do N
	// entao eles podem fazer um set{1...N-1}
	// e jogar para sempre
	if(!hasN) {
		cout << "inf\n";
		return 0;
	}

	int total = 0; // guess this is flow;
	vector<pair<string, int>> ans;

	// getting 
	int mStuff = 1e11;
	for(auto [a, b, c]: v) {
		if(a == n-1 || b == n-1) mStuff = min(mStuff, c);
	}
	string ms(n, '1');
	ms.back() = '0';
	if(mStuff)
		ans.emplace_back(ms, mStuff);

	Dinitz d(n+m+10, n+m+2, n+m+3);

	for(int i = 0; i < n; i++) {
		d.add_edge(d.s, i, oo);
	}
	for(int i = 0; i < m; i++) {
		auto [a, b, c] = v[i];
		if(a == n-1 || b == n-1) continue;

		d.add_edge(i+n, d.t, c);
		d.add_edge(a, i+n, oo);
		d.add_edge(b, i+n, oo);
	}

	total = d.flow();

	// here do the stuff;

	cout << total << ' ' << ans.size() << '\n';
	for(auto [a, b]: ans) cout << a << ' ' << b << '\n';
}
