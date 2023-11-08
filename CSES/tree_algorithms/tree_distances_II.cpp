#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n; cin >> n;
	vector<vector<int>> arv(n);
	for(int i = 1; i < n; i++) {
		int a, b; cin >> a >> b; a--, b--;
		arv[a].push_back(b);
		arv[b].push_back(a);
	}
}
