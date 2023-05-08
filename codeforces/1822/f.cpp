#include <bits/stdc++.h>

using namespace std;

#define int long long

const int oo = 1e16;
const int MAXN = 3e5;
int n, k, c;
vector<int> tree[MAXN];
vector<int> dist(MAXN);
vector<int> dia(MAXN), pre(MAXN);

void dfs(int u=1, int v=1, int d=0) {

	dist[u] = d;

	for(auto el: tree[u]) if(el != v) {
		dfs(el, u, d+1);
	}	
}

void calc(int u=1, int v=1) {

	int height = 0;

	for(auto el: tree[u]) if(el != v) {
		calc(el, u);
		height = max(pre[el] + 1, height);
	}
	pre[u] = height;
}

void fim(int u=1, int v=1, int maxi=0) {


	int len = 0;
	pair<int,int> max1(-1, -1), max2(-1, -1);
	for(auto el: tree[u]) if(el != v) {
		len = max(len, pre[el]+1);

		if(pair<int,int>(pre[el]+1, el) > max1) {
			max2 = max1;
			max1 = pair<int,int>(pre[el]+1, el);
		}
	}	

	for(auto el: tree[u]) if(el != v) {
		if(el == max1.second) {
			fim(el, u, max(maxi+1, max2.first+1));
		}else fim(el, u, max(maxi+1, max1.first+1));
	}

	/*
	cout << "to no " << u << " pai = " << v << " maxi = " << maxi << endl;
	cout << "Len = " << len << endl;
	*/
	dia[u] = max(len, maxi);
}

void solve() {
	cin >> n >> k >> c;
	for(int i = 0; i <= n; i++) {
		tree[i].clear();
		dist[i] = 0;
		dia[i] = 0;
		pre[i] = 0;
	}

	for(int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs();
	calc();
	fim();

	int ans = 0;

	for(int i = 1; i <= n; i++) {
		/*
		cout << "--------------\n";
		cout << dia[i] << ' ' << dist[i] << endl;
		*/
		ans = max(ans, dia[i]*k - dist[i]*c); 
	}

	cout << ans << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t=1;
	cin >> t;
	while(t--) solve();
}
