#include <bits/stdc++.h>

using namespace std;
#define int long long

using ii = pair<int,int>;

struct dsu {
	vector<int> pai;
	int n;

	dsu(int _n): n(_n) {
		pai.resize(n);
		iota(begin(pai), end(pai), 0LL);
	}

	int find(int x) {
		return x == pai[x] ? x : pai[x] = find(pai[x]);
	}

	void join(int x, int y) {
		x = find(x);
		y = find(y);
		if(x == y) return;
		pai[y] = x;
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<ii> edges;
	dsu d(n);

	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--, b--;
		edges.emplace_back(a, b);
		d.join(a, b);
	}

	int k;
	cin >> k;
	vector<int> c(k);
	set<int> same;
	for(auto& it: c) {
		cin >> it;
		same.insert(d.find(it));
	}

	if(same.size() > 1) {
		cout << -1 << endl;
		return 0;
	}


}
