#include <bits/stdc++.h>

using namespace std;
#define int long long

using iii = array<int,3>;

const int oo = 1e18;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<iii> edges(m);
	vector<int> in(n), out(n);
	for(auto& [a, b, c]: edges) {
		cin >> a >> b >> c;
		a--, b--;
		in[b]++;
		out[a]++;
	}

	vector<int> dist(n, oo);
	bool leaf = false;
	for(int i = 0; i < n; i++)
		if(!in[i])
			leaf=true, dist[i] = 0;
	if(!leaf) {
		for(int i = 0; i < n; i++) {
			if(out[i]) {
				dist[i] = 0;
				break;
			}
		}
	}

	for(int i = 0; i < n-1; i++) {
		for(auto [a, b, w]: edges) {
			if(dist[a] < oo && dist[b] > dist[a] + w) {
				dist[b] = dist[a] + w;
			}
		}
	}

	vector<bool> negCycle(n);
	vector<int> parent(n);
	bool neg = false;
	int start;

	for(int i = 0; i < n-1; i++) {
		for(auto [a, b, w]: edges) {
			if(dist[a] < oo && dist[b] > dist[a] + w) {
				negCycle[b] = true;
				neg = true;
				parent[b] = a;
				start = b;
			}

			if(negCycle[a]) {
				parent[b] = a;
				negCycle[b] = true;
				start = b;
			}
		}
	}

	if(!neg) return cout << "NO\n", 0;

	cout << "YES\n";
	// has to recover path/ answer
	vector<int> ans;
	set<int> found;
	while(found.find(start) == end(found)) {
		found.insert(start);
		start = parent[start];
	}

	int ini = start;
	ans.push_back(start);
	start = parent[start];
	while(start != ini) {
		ans.push_back(start);
		start = parent[start];
	}
	ans.push_back(start);
	reverse(begin(ans), end(ans));
	for(auto it: ans) cout << it+1 << ' ';
	cout << endl;
}
