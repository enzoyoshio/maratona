#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n; cin >> n;
		string s; cin >> s;

		int qt = 0;
		for(int i = 0; i < n; i++) {
			qt += s[i] != s[n-1-i];
		}

		vector<int> ans(n+1);
		int same = n-qt;
		if(n%2 == 0) {
			for(int i = 0; i <= same; i+=2)
				ans[qt/2+i] = 1;
		}else {
			for(int i = 0; i <= same; i++)
				ans[qt/2+i] = 1;
		}
		for(auto it: ans) cout << it;
		cout << '\n';
	}
}
