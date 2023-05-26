#include <bits/stdc++.h>
 
using namespace std;
#define int long long

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"
 
const int MAXN = 2e6+8;
const int MAXL = 25;
int n, q;
int timer = 0;
vector<vector<int>> arv(MAXN);
int up[MAXN][MAXL];
int tin[MAXN], tout[MAXN];
int ans[MAXN];
 
void tour(int u, int p) {
	tin[u] = timer++;
	
	up[u][0] = p;
	for(int i = 1; i < MAXL; i++)
		up[u][i] = up[up[u][i-1]][i-1];
 
	for(auto v: arv[u]) if(v != p)
		tour(v, u);
 
	tout[u] = timer;
}
 
bool is_ancestor(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}
 
void lca(int u, int v) {
	
	if(u == v) {
		ans[u]++;
		ans[up[u][0]]--;
		return;
	}
 
	if(is_ancestor(u, v)) {
		ans[v]++;
		ans[up[u][0]]--;
		return;
	}
	
	if(is_ancestor(v, u)) {
		ans[u]++;
		ans[up[v][0]]--;
		return;
	}
 
	ans[u]++;
	ans[v]++;
 
	for(int i = MAXL-1; i >= 0; i--) {
		if(!is_ancestor(up[u][i], v)) {
			u = up[u][i];
		}
	}
 
	ans[up[u][0]]--;
  ans[up[u][1]]--;
}
 
int dfs(int u, int p) {
  for(auto& v: arv[u]) 
    if(v != p)
      ans[u] += dfs(v, u);
	return ans[u];
}
 
signed main() {
	cin.tie(0)->sync_with_stdio(false);
 
	cin >> n >> q;
 
	for(int i = 1; i < n; i++) {
		ans[i] = ans[i-1] = ans[i+1] = 0;
		int a, b; 
		cin >> a >> b;
		arv[a].emplace_back(b);
		arv[b].emplace_back(a);
	}
  
  arv[0].emplace_back(1);
	arv[1].emplace_back(0);
	
  tour(0, 0);
  
  while(q--) {
    int a, b; cin >> a >> b;
    lca(a, b);
  }

	dfs(0, 0);
 
	for(int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	cout << endl;
}

// 10 10
// 9 6
// 6 10
// 5 10
// 3 7
// 8 1
// 6 4
// 8 7
// 5 8
// 1 2
// 3 3
// 9 1
// 8 9
// 7 4
// 7 9
// 1 6
// 3 2
// 3 2
// 3 9
// 2 6

