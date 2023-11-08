#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e18;

using iii = tuple<int,int,int>;
//using iii = array<int,3>;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<pair<int,int>>> g(n);
	vector<iii> edges;

	for(int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c; a--, b--;
		c = -c;
		edges.emplace_back(a, b, c);

		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}

	vector<int> dist(n, oo);
	dist[0] = 0;

	for(int i = 0; i < n; i++)
		for(auto [a, b, w]: edges)
			if(dist[a] < oo && dist[b] > dist[a] + w)
				dist[b] = dist[a] + w;

  vector<int> neg(n);

  for(int i = 0; i < n; i++)
    for(auto [a, b, w]: edges) {
      if(dist[a] == oo) continue;

      if(dist[b] > dist[a] + w) {
        dist[b] = dist[a] + w;
        neg[b] = 1;
      }

      if(neg[a])
        neg[b] = 1;
    }


  if(neg.back()) cout << -1 << endl;
  else
    cout << -dist.back() << endl;
}
