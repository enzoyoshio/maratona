#include <bits/stdc++.h>

using namespace std;
#define int long long

struct DSU {
	vector<int> pai;
	int n;

	DSU(int n) : n(n), pai(n) {
		iota(begin(pai), end(pai), 0LL);
	}

	int find(int x) {
		return x == pai[x] ? x : pai[x] = find(pai[x]);
	}

	void join(int x, int y) {
		x = find(x);
		y = find(y);
		if(x == y) return;

		pai[x] = y;
	}
};

using iii = array<int,3>;

vector<int> ans;
vector<vector<pair<int,int>>> g;
int cost = 0;

void dfs(int u, int p) {
	ans.push_back(u);

	bool child = true;
	for(auto [v, w]: g[u]) if(v != p) {
		dfs(v, u);
		child = false;
		ans.push_back(u);
	}

}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	g.resize(n);

	vector<iii> edges(m);
	for(auto& [a, b, c]: edges) cin >> b >> c >> a, b--, c--;
	sort(begin(edges), end(edges));

	DSU d(n);

	for(auto [w, a, b]: edges) {
		if(d.find(a) == d.find(b)) continue;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
		d.join(a, b);
		cost += w;
	}

	dfs(0, 0);

	cout << 2*cost << endl;
	cout << ans.size() << endl;
	for(auto it: ans) cout << it+1 << ' ';
	cout << endl;
}
