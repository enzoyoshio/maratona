#include <bits/stdc++.h>

using namespace std;

struct dsu {
	int n;
	vector<int> pai, tam, ed;

	dsu(int n): n(n) {
		pai.assign(n, 0);
		tam.assign(n, 1);
		ed.assign(n, 0);

		iota(pai.begin(), pai.end(), 0LL);
	}

	int find(int x) { return x == pai[x] ? x : pai[x] = find(pai[x]);}

	void join(int x, int y) {
		if(find(x) == find(y)) {
			ed[find(x)]++;
			return;
		}

		x = find(x);
		y = find(y);

		if(tam[x] < tam[y]) swap(x, y);

		tam[x] += tam[y];
		ed[x] += ed[y] + 1;
		pai[y] = x;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	dsu d(n);

	while(m--) {
		int a, b; cin >> a >> b; a--, b--;

		d.join(a, b);
	}

	for(int i = 0; i < n; i++) {
		if(d.find(i) == i && d.tam[i] != d.ed[i]) {
			return cout << "No\n", 0;
		}
	}
	cout << "Yes\n";
}
