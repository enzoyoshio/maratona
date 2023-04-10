#include <bits/stdc++.h>

using namespace std;

struct dsu {
	vector<int> pai, cycle;
	
	dsu(int n) {
		pai.resize(n);
		cycle.assign(n, 1);
		iota(pai.begin(), pai.end(), 0);
	}

	int find(int x) {
		return x == pai[x] ? x : pai[x] = find(pai[x]);
	}

	void join(int x, int y) {
		x = find(x);
		y = find(y);
		if(x == y) return;

		pai[y] = x;
		cycle[x] |= cycle[y];
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	vector<int> deg(n);
	dsu d(n);

	for(int i = 0; i < m; i++) {
		int a, b; char c, e;
		cin >> a >> c >> b >> e;

		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
		deg[a]++, deg[b]++;
		d.join(a, b);
	}

	for(int i = 0; i < n; i++) {
		if(deg[i] <= 1) {
			d.cycle[d.find(i)] = 0;
		}
	}

	int x = 0, y = 0;
	for(int i = 0; i < n; i++) {
		if(d.find(i) == i) {
			if(d.cycle[i]) {
				x++;
			}
			else {
				y++;
			}
		}
	}
	cout << x << ' ' << y << endl;
}
