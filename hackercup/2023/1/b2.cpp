#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t;
	for(int i = 1; i <= t; i++) {

		int n;
		cin >> n;
		
		map<int,int> mp;
		for(int i = 2; i*i <= n; i++) {
			while(n%i == 0) {
				mp[i]++;
				n /= i;
			}
		}
		if(n > 1) mp[n]++;

		cout << "Case #" << i << ": ";

		int sum = 0;
		for(auto [a, b]: mp) {
			sum += a*b;
		}

		if(sum <= 41) {
			vector<int> ans;
			for(auto [a, b]: mp)
				for(int j = 0; j < b; j++)
					ans.push_back(a);
			while(sum < 41) ans.push_back(1), sum++;
			cout << ans.size() << ' ';
			for(auto it: ans) cout << it << ' ';
			cout << '\n';
		}else {
			cout << -1 << '\n';
		}
	}
}
