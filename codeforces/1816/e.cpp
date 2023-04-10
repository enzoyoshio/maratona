#include <bits/stdc++.h>

using namespace std;

#define int long long

#define FINITE cout << "FINITE\n"
#define INFINITE cout << "INFINITE\n"
vector<vector<int>> g, h;
vector<int> vis, altura;

bool dfs(int u=1, int alt=1) {
	
	vis[u] = 1;
	h[alt].push_back(u);
	altura[u] = alt;

	bool has = false;
	for(auto v: g[u]) {

		if(!vis[v])
			has |= dfs(v, alt+1);
	}
	return has;
}

int solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> edg(m);
	g.assign(n+8, vector<int>());
	h.assign(n+8, vector<int>());
	vis.assign(n+8, false);
	altura.assign(n+8, 0);
	
	for(auto& [a, b]: edg) {
		cin >> a >> b;
		if(a > 1)
			g[b].push_back(a);
	}

	if(m == 0) {
		if(n == 1) {
			FINITE;
			cout << 1 << endl << 1 << endl;
		}else INFINITE;

		return 0;
	}

	// implementar isso
	auto ret = dfs();

	// montar arvore
	// se possuir uma floresta
	// entao eh infinite
	for(int i = 2; i <= n; i++)
		if(!vis[i]) return INFINITE, 0;

	// como construir a resposta? 
	//

	int maxH = 0;
	for(int i = 1; i < (int)h.size(); i++) {
		if(h[i].size()) maxH = i;
	}	

	vector<int> ans;
	for(int i = 1; i <= maxH; i++) {
		for(int j = maxH; j >= i; j--) {
			for(auto el: h[j])
				ans.push_back(el);
		}
	}

	FINITE;
	cout << ans.size() << endl;
	for(auto el: ans)
		cout << el << ' ';
	cout << endl;

	return 0;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t=1;
	cin >> t;
	while(t--) solve();
}
