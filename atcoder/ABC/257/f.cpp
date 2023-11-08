#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9;

int n, m;
vector<int> portal;
vector<vector<int>> g;

vector<int> bfs(int source) {
	vector<int> dist(n+3, oo);

	queue<int> q;
	dist[source] = 0;
	q.push(source);

	while(q.size()) {
		auto u = q.front(); q.pop();
		for(auto v: g[u]) if(dist[v] == oo) {
			dist[v] = dist[u] + 1;
			q.push(v);
		}
	}
	return dist;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m;
	g.resize(n+3);
	vector<int> ans(n+10, oo);

	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		if(!a) {
			portal.push_back(b);
		}else if(!b) {
			portal.push_back(a);
		}else {
			g[a].push_back(b);
			g[b].push_back(a);
		}	
	}

	auto dist1 = bfs(1);
	auto distN = bfs(n);

	int min_from1 = oo, min_fromN = oo;

	for(auto p: portal) {
		min_from1 = min(min_from1, dist1[p]);
		min_fromN = min(min_fromN, distN[p]);
	}

	for(int i = 1; i <= n; i++) {
		ans[i] = min(ans[i], min_from1 + distN[i]+1);
		ans[i] = min(ans[i], min_fromN + dist1[i]+1);
		ans[i] = min(ans[i], min_from1 + min_fromN+2);
		ans[i] = min(ans[i], dist1[n]);
		ans[i] = min(ans[i], distN[1]);
	}

	for(int i = 1; i <= n; i++) {
		int it = ans[i];
		if(it >= oo) cout << -1 << ' ';
		else cout << it << ' ';
	}
	cout << endl;
}
