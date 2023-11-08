#include <bits/stdc++.h>

using namespace std;
#define int long long

using ii = pair<int,int>;
int n, m;
vector<vector<ii>> g;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m;
	g.resize(n);
	for(int i = 0; i < m; i++) {
		int v, u, w; cin >> v >> u >> w;
		v--, u--;
		g[v].emplace_back(u, w);
		g[u].emplace_back(v, w);
	}

	int q; cin >> q;
	while(q--) {

	}
}
