#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int m, k, a1, ak;
		cin >> m >> k >> a1 >> ak;
		int ori = m;
		
		int qt = m/k;
		m -= min(qt, ak)*k;
		m -= min(m, a1);

		int big = m/k + m%k;

		int df = k-m%k;

		int ss = 1e9;
		if(a1 >= df) 
			ss = (m+k-1)/k;
		cout << min(ss, big) << '\n';


	}
}
