#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v, g;
vector<int> vis;

void dfs(int u, int p, int c) {
  if(u != c) v[c][u] = 1;
  vis[u] = c;
  for(auto v: g[u]) if(v != p && vis[v] < c) dfs(v, u, c);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

  v.resize(n, vector<int>(n, 0));
  g.resize(n);
  vis.resize(n, -1);

  for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--, b--;

		v[a][b] = 1;
    g[a].push_back(b);
	}

  for(int i = 0; i < n; i++)
    dfs(i, i, i);

  int ans = 0;
  for(auto it: v)
    ans += accumulate(begin(it), end(it), 0LL);

  cout << ans - m << endl;

}
