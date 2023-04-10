#include <bits/stdc++.h>

using namespace std;

void solve() {
	int m;
	cin >> m;

	map<int,int> last;
	vector<int> ans(m, -1);

	for(int i = 0; i < m; i++) {
		int n; cin >> n;
		for(int j = 0; j < n; j++) {
			int num; cin >> num;
			last[num] = i;
		}
	}

	for(auto [num, ult]: last) {
		if(ans[ult] == -1) ans[ult] = num;
	}

	if(*min_element(ans.begin(), ans.end()) == -1) {
		cout << -1;
	}else 
		for(auto el: ans)
			cout << el << ' ';
	cout << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t = 1;
	cin >> t;
	while(t--) solve();
}
