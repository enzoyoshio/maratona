#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;

struct DSU {
	vector<int> p, t;
	int n;

	DSU(int n) : n(n), p(n), t(n, 1) {
		iota(begin(p), end(p), 0LL);
	}

	int find(int x) { return x == p[x] ? x : p[x] = find(p[x]);}

	int size(int x) { return t[find(x)];}

	void join(int x, int y) {
		x = find(x); y = find(y);
		if(x == y) return;

		if(t[x] < t[y]) swap(x, y);
		t[x] += t[y];
		p[y] = x;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for(auto& it: v) cin >> it, it--;
	
	vector<pair<int,int>> ordered;	
	for(int i = 0; i < n; i++) {
		ordered.emplace_back(v[i], i);
	}
	sort(begin(ordered), end(ordered));

	auto find = [&](int x, int id) {
		return lower_bound(begin(ordered), end(ordered), ii{x, id})
		      -begin(ordered);
	};

	map<pair<int,int>, pair<int,int>> nxt;
	map<pair<int,int>, pair<int,int>> parent;
	vector<bool> vis(n);	

	for(int i = 0; i < n; i++) {
		if(vis[i]) continue;
		int idx = i;

		set<pair<int,int>> same;

		while(!vis[i]) {
			same.emplace(v[i], i);
			vis[i] = true;
			auto pos = find(v[i], i);
			nxt[{v[i], i}] = {v[pos], pos};
			parent[{v[pos], pos}] = {v[i], i};

			auto lb = same.lower_bound(pair<int,int>(v[pos], 0));

			if(lb != end(same) && lb->first == v[pos]) {
				cout << "amigo estou aqui\n";
				auto [nxpos, npi] = *lb;
				auto [painx, paid] = parent[*lb];
				int par_i_val = parent[{v[i], i}].first;
				int par_i_idx = parent[{v[i], i}].second;

				nxt[parent[*lb]] = {v[pos], pos};
				parent[{v[pos], pos}] = parent[*lb];
				nxt[{v[i], i}] = *lb;
				parent[*lb] = {v[i], i};
			}
			i = pos;
		}

		i = idx;
	}

	DSU d(n);

	for(int i = 0; i < n; i++) {
		d.join(i, nxt[{v[i], i}].second);
	}

	int ans = 0;
	for(int i = 0; i < n; i++) {
		cout << "v[i] " << v[i] << " is in cycle " << d.find(i) << endl;
		if(d.find(i) == i) ans += d.size(i)-1;
	}
	cout << ans << endl;
}
