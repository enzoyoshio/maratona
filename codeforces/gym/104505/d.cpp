#include <bits/stdc++.h>

using namespace std;
#define int long long

using iii = array<int,3>;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k; cin >> n >> k;
	vector<iii> ranges(n);
	vector<queue<int>> filas(k);

	for(int i = 0; i < 2*n; i++) {
		int t; cin >> t;

		if(t == 1) {
			int p, f; cin >> p >> f;
			p--, f--;
			ranges[p][0] = i;
			ranges[p][2] = p;
			filas[f].push(p);
		}else {
			int f; cin >> f;
			f--;
			auto ff = filas[f].front(); filas[f].pop();
			ranges[ff][1] = -i;
		}
	}

	sort(begin(ranges), end(ranges));

	vector<int> ans;
	set<int> rights;
	for(int i = n-1; i >= 0; i--) {

		auto ub = rights.upper_bound(abs(ranges[i][1]));

		if(ub != begin(rights)) {
			ans.push_back(ranges[i][2]+1);
		}

		rights.insert(abs(ranges[i][1]));
	}

	sort(begin(ans), end(ans));

	cout << ans.size() << endl;
	for(auto ie: ans) cout << ie << ' ';
	cout << endl;
}
