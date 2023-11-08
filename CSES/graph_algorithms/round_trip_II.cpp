#include <bits/stdc++.h>

using namespace std;
#define int long long

int start = -1;
vector<int> pai, vis;
vector<vector<int>> g;

void dfs(int cur, int p, int level) {

	vis[cur] = -1;
	pai[cur] = p;

	for(auto v: g[cur]) {
		if(start == -1 && vis[v] == -1) {
			start = cur;
			pai[v] = cur;
		}
		if(!vis[v]) dfs(v, cur, level);
	}

	vis[cur] = level;

}

signed main() {
	// this ideia is right but its too late now
	// I need to sleep
	// just reimplement this with dfs
	//cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	pai.resize(n);
	vis.resize(n);
	g.resize(n);
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
	}


	for(int i = 0; i < n; i++) {
		if(vis[i]) continue;

		dfs(i, i, i+1);
	}

	if(start == -1) return cout << "IMPOSSIBLE\n", 0;

	vector<int> ans = {start};
	int idx = pai[start];

	while(idx != start) {
		ans.push_back(idx);
		idx = pai[idx];
	}	
	ans.push_back(start);
	reverse(begin(ans), end(ans));
	cout << ans.size() << endl;
	for(auto it: ans) cout << it+1 << ' ';
	cout << endl;
}
