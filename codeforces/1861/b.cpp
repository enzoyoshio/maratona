#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		string a, b;
		cin >> a >> b;

		bool can = false;
		for(int i = 0; i+1 < a.size(); i++) {
			if(a[i] == '0' && b[i] == '0'
			&& a[i+1] == '1' && b[i+1] == '1') can = true;
		}
		cout << (can ? "YES" : "NO") << '\n';
	}
}
