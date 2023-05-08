#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n, m;
		cin >> n >> m;
		vector<int> v(n);
		for(auto& it: v)
			cin >> it, it--;

		string ans(m, 'B');

		for(int i = 0; i < n; i++) {
			int other = m-v[i]-1;

			int mn = min(other, v[i]), mx = max(other, v[i]);
			if(ans[mn] != 'A') ans[mn] = 'A';
			else ans[mx] = 'A';
		}
		cout << ans << endl;
	}
}
