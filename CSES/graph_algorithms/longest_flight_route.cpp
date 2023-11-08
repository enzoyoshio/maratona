#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, m;
vector<vector<int>> g;
vector<int> h, filho;

void dfs(int idx) {

	if(~h[idx]) return;

	h[idx] = 1;
	for(auto it: g[idx]) {
		dfs(it);
		if(h[idx] < 1 + h[it]) {
			h[idx] = 1+h[it];
			filho[idx] = it;
		}
	}

	if(h[idx] == 1 && idx != n-1)
		h[idx] = -2;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m;
	g.resize(n);
	h.resize(n, -1);
	filho.resize(n, -1);

	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
	}

	dfs(0);

	if(h[0] == -2) return cout << "IMPOSSIBLE\n", 0;

	vector<int> path;
	int idx = 0;

	while(idx != -1) {
		path.push_back(idx);
		idx = filho[idx];
	}

	cout << h[0] << endl;
	for(auto it: path) cout << it+1 << ' ';
	cout << endl;
}
