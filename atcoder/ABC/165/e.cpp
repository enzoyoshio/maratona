#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	int n, m;
	cin >> n >> m;

	if(n%2 == 0) {
		vector<pair<int,int>> ans((n-1)/2);
		ans[0].first = 1;
		for(int i = 1; i < (int)ans.size(); i++) ans[i].first = ans[i-1].first+1;
		ans.back().second = ans.back().first+1;
		bool first = true;
		for(int i = (int)ans.size()-2; i >= 0; i--) {
			ans[i].second = ans[i+1].second+1;
			if(first && ans[i].second-ans[i].first - 1 >= (n)/2) first = false, ans[i].second++;
		}

		for(int i = 0; i < m; i++) cout << ans[i].first << ' ' << ans[i].second << '\n';
//		for(int i = 0; i < m; i++) cout << ans[i].second - ans[i].first -1 << endl;
		return 0;
	}
	int left = 1, right = n;
	for(int i = 0; i < m; i++) cout << left << ' ' << right << '\n', left++, right--;
}
