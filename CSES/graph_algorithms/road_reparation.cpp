#include <bits/stdc++.h>

using namespace std;
#define int long long

using iii = array<int,3>;

struct DSU {
	vector<int> pai, tam;
	int n;

	DSU(int n) : n(n), pai(n), tam(n, 1) {
		iota(begin(pai), end(pai), 0LL);
	}

	int find(int x) {
		return x == pai[x] ? x : pai[x] = find(pai[x]);
	}

	void join(int x, int y) {
		x = find(x); y = find(y);
		if(x == y) return;

		if(y < x) swap(x, y);
		pai[x] = y;
		tam[y] += tam[x];
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<iii> edges(m);

	for(auto& [a, b, c]: edges) cin >> b >> c >> a, b--, c--;
	sort(begin(edges), end(edges));

	DSU d(n);
	int cost = 0;
	for(auto [w, a, b]: edges) {
		if(d.find(a) != d.find(b)) {
			cost += w;
			d.join(a, b);
		}
	}

	if(d.tam[d.find(0)] != n) return cout << "IMPOSSIBLE\n", 0;
	cout << cost << endl;
}
