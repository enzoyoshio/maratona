#include <bits/stdc++.h>

using namespace std;
#define int long long

using iii = array<int,3>;

struct DSU {
	vector<int> pai, tam;
	int n;
	int ans1, ans2;

	DSU(int n) : n(n), pai(n), tam(n, 1) {
		iota(begin(pai), end(pai), 0LL);
		ans1 = n, ans2 = 1;
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
		ans1--;
		ans2 = max(ans2, tam[y]);
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	DSU d(n);

	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--, b--;
		d.join(a, b);
		cout << d.ans1 << ' ' << d.ans2 << '\n';
	}
}
