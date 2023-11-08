#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for(int i = 0; i < m; i++) {
		int a; cin >> a; a--;
		v[a]++;
	}

	vector ans(n, 0);

	int idx = n-1;

	for(int i = n-2; i >= 0; i--) {
		if(v[i]) idx = i;

		ans[i] = idx-i;
	}

	for(auto it: ans) cout << it << endl;
}
