#include <bits/stdc++.h>

#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#pragma GCC optimize("O3,unroll-loops")

using namespace std;

using piv = pair<int, vector<int>>;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(n, 0));
	vector<piv> to(n, piv());

	while(m--) {
		int a, b; cin >> a >> b;
		a--, b--;

		v[a][b] = 1;
		to[a].first = a;
		to[a].second.push_back(b);
	}

	sort(to.begin(), to.end(), [](piv a, piv b) {
		return a.second.size() < b.second.size();
			});

	int ans = 0;

	for(int i = 0; i < n; i++) {
		int aux = i;
		for(auto el: to[i].second) {

		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j) continue;

			if(v[i][j]) {
				queue<int> q;
				for(auto el: to[j])
					if(i != el)
						q.emplace(el);
				
				while(q.size()) {
					auto u = q.front(); q.pop();

					//cout << i << ' ' << j << ' ' <<  u << '\n';
					if(v[i][u]) continue;

					ans++;
					v[i][u] = 1;
					to[i].push_back(u);
					for(auto el: to[u])
						if(!v[i][el] && i != el)
							q.emplace(el);
				}
			}
		}
	}

	cout << ans << endl;
	
}
