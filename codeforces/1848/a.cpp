#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n, m, k; cin >> n >> m >> k;

		int x, y; cin >> x >> y;

		bool pega = false;

		for(int i = 0; i < k; i++) {
			int a, b; cin >> a >> b;
			if((a+b)%2 == (x+y)%2) pega = true;	
		}
		if(pega) cout << "No\n";
		else cout << "Yes\n";
	}
}
