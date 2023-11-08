#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9+7;

int add(int a, int b) { return (a+b)%MOD;}
int mul(int a, int b) { return (a*b)%MOD;}
int fexp(int b, int e) {
	if(e == 0) return 1LL;

	int x = fexp(b, e/2);
	x = mul(x, x);

	if(e%2) x = mul(x, b);

	return x;
}

int n;
vector<vector<pair<int,int>>> G;
vector<int> pref;

void dfs(int u=0, int p=0) {
	pref[u] = pref[u] xor pref[p];
	for(auto [v, w]: G[u]) if(v != p) {
		pref[v] = pref[v] xor w;
		dfs(v, u);
	}
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n;
	G.resize(n);
	pref.resize(n);
	for(int i = 1; i < n; i++) {
		int u, v, w; cin >> u >> v >> w;
		u--, v--;
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	}

	// montar o prefix xor a partir de uma raiz
	dfs();

	int ans = 0LL;
	vector<vector<int>> qt(60, vector<int>(2, 0));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 60; j++) {
			bool bit = pref[i] >> j & 1;
			ans = add(ans, mul(qt[j][!bit], fexp(2, j)));
			qt[j][bit]++;
		}	
	}
	cout << ans << endl;
}
