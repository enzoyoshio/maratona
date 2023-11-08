#include <bits/stdc++.h>

using namespace std;
#define int long long

using iii = array<int, 3>;

const int oo = 1e18;

struct DSU {
	vector<int> pai;
	int n;

	DSU() {}

	DSU(int n): n(n) {
		pai.resize(n);
		iota(begin(pai), end(pai), 0LL);
	}

	int find(int x) {
		return x == pai[x] ? x : pai[x] = find(pai[x]);
	}

	void merge(int a, int b) {
		a = find(a);
		b = find(b);
		if(a == b) return;

		pai[a] = b;
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<iii> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i][0] >> v[i][1];
		v[i][2] = i;
	}

	DSU d(n);

	sort(begin(v), end(v));

	vector<iii> edges(2*(n-1));

	for(int i = 0; i+1 < n; i++) {
		edges[i] = {min(abs(v[i][0] - v[i+1][0]), abs(v[i][1] - v[i+1][1])), v[i][2], v[i+1][2]};
	}

	for(auto& [a, b, c]: v) swap(a, b);
	sort(begin(v), end(v));
	for(int i = 0; i+1 < n; i++) {
		edges[i+n-1] = {min(abs(v[i][0]-v[i+1][0]), abs(v[i][1] - v[i+1][1])), v[i][2], v[i+1][2]};
	}

	sort(begin(edges), end(edges));

	int ans = 0;
	for(auto [cost, a, b]: edges) {
		if(d.find(a) == d.find(b)) continue;

		ans += cost;
		d.merge(a, b);

	}

	cout << ans << endl;
}
