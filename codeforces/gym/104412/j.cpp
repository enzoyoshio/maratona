#include <bits/stdc++.h>

using namespace std;
#define int long long

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"

#define miq(a, b) if(b < a) a = b;

const int oo = 1e9;
const int MAXN = 1e5+8;
int n, m, q;
vector<vector<int>> g(MAXN);
vector<int> h(MAXN, oo), backedge(MAXN, MAXN);
vector<int> pai(MAXN), conta(MAXN);
vector<bool> vis(MAXN);
unordered_map<int, int> rep;

int find(int x) { return x == pai[x] ? x : pai[x] = find(pai[x]);}
void join(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return;
	pai[a] = b;
}

void dfs(int u=0, int p=0) {

	/*
	cout << "\n\n--------------- db ---------------\n";
	db(u);
	db(p);
	cout << " entradas acima\n";
	*/
	//if(++conta[u] > 1) assert(false);

	h[u] = h[p]+1;
	for(auto v: g[u]) if(v != p) {
		if(rep[u << 32 | v] > 1) {
			miq(backedge[u], u);
			miq(backedge[v], u);
		}

		if(h[v] == oo) dfs(v, u);

		// this is a backedge
		if(h[v] < h[u]) {
			miq(backedge[v], v);
			miq(backedge[u], backedge[v]);
		}else {
			/*
			cout << "\n\nentrando\n";
			db(u);
			db(h[u]);
			db(v);
			db(h[v]);
			*/

			miq(backedge[u], backedge[v]);
		}
	}

	/*
	db(h[u]);
	db(backedge[u]);
	*/
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m >> q;
	h[0] = 0;
	for(int i = 0; i < n; i++) pai[i] = i;

	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--, b--;
		rep[a << 32 | b]++;
		rep[b << 32 | a]++;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs();

	queue<int> Q;

	for(int i = 0; i < n; i++) {
		if(backedge[i] == MAXN) {
			Q.push(i);
			vis[i] = true;

			while(Q.size()) {
				auto cur = Q.front(); Q.pop();

				for(auto v: g[cur]) if(!vis[v] && backedge[v] == MAXN)
					Q.push(v), vis[v] = true, join(cur, v);

			}

		}
	}

	for(int i = 0; i < q; i++) {
		int a, b; cin >> a >> b;
		a--, b--;
		if(find(a) == find(b)) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
