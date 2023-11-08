#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e18;

using ii = pair<int,int>;
using iii = array<int,3>;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<ii>> g(n);
	set<iii> edges;

	for(int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.emplace(a, b, c);
		edges.emplace(b, a, c);
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}

	vector<int> dist(n, oo);
	dist[0] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	vector<int> parent(n, -1);
	pq.push({0, 0});

	while(pq.size()) {
		auto [d, id] = pq.top(); pq.pop();

		if(d >= dist[id]) continue;

		for(auto [v, d1]: g[id]) {
			if(d + d1 < dist[v]) {
				dist[v] = d + d1;
				pq.push({dist[v], v});
				parent[v] = id;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		if(parent[i] != -1) {
			edges.erase(edges.lower_bound({i, parent[i], 0}));
			edges.erase(edges.lower_bound({parent[i], i, 0}));
		}
	}

	vector<vec
}
