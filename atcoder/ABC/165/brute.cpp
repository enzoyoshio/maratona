#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	int n, m;
	cin >> n >> m;

	if(n%2 == 0) {
		vector<pair<int,int>> ans(m);
		ans[0].first = 1;
		ans[0].second = n;
		for(int i = 1; i < ans.size(); i++) ans[i].first = ans[i-1].first + 1, ans[i].second = ans[i-1].second-1;
		for(int i = 0; i < m; i++) cout << ans[i].first << ' ' << ans[i].second + (ans[i].second-ans[i].first-1 < n/2 ? -1 : 0) << '\n';
		return 0;
	}
	int left = 1, right = n;
	for(int i = 0; i < m; i++) cout << left++ << ' ' << right-- << '\n';
}
