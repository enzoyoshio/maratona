#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> path;
int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, s, t;
	cin >> n >> s >> t;

	g.assign(n, vector<int>());

	for(int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	getPath(s, t);
	getHeight(s);	

	if(path[0] != s) reverse(path.begin(), path.end());

	int ans = 0;
	for(auto p: path) {
		if(height[p] >= height[t]/2) {
			ans = max(ans, height[t]-height[p]);
			continue;
		}
	}
}
