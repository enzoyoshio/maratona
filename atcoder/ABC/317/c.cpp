#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e8;

signed main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> dist(n, vector<int>(n, -oo));

	for(int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		dist[a][b] = c;
		dist[b][a] = c;

	}

	vector<int> idx(n);
	iota(begin(idx), end(idx), 0LL);

	int ans = 0;
	do {

		int cur = 0;
		for(int i = 1; i < n; i++) {
			cur += dist[idx[i-1]][idx[i]];
			ans = max(ans, cur);
		}
	}while(next_permutation(begin(idx), end(idx)));
	cout << ans << endl;
}
