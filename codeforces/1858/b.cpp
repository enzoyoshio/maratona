#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e18;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n, m, d;
		cin >> n >> m >> d;
		vector<int> v(m+2);
		v[0] = 1; v[m+1] = n;
		for(int i = 1; i <= m; i++)
			cin >> v[i];

		// how much he eats between 
		// interval (i-1, i]
		vector<int> inter(m+2);

		for(int i = 1; i < m+1; i++) {
			inter[i] = (v[i]-v[i-1]+d-1)/d;
		}
		if(v[1] != 1) inter[0] = 1;
		else inter[1] = 1;

		inter[m+1] = (v[m+1] - v[m])/d;
//		if(v[m] == n) inter[m+1] = 0;

		for(int i = 1; i <=m+1; i++)
			inter[i] += inter[i-1];

		/*
		for(int i = 0; i <= m+1; i++)
			cout << inter[i] << ' ';
		cout << endl;
		*/

		int best = oo, qt = 0;

		for(int i = 1; i <= m; i++) {

			if(v[i] == 1) {
				int tot = inter.back();
				if(tot <= best) {
					if(tot < best) qt = 0;
					qt++;
					best = tot;
				}
				continue;
			}else if(v[i] == n) {
				int left = inter[i-1];
				int right = (n-v[i-1])/d;
				int tot = left + right;
				if(tot <= best) {
					if(tot < best) qt = 0;
					qt++;
					best = tot;
				}
				continue;
			}

			int left = inter[i-1];
			int right = inter.back() - inter[i+1];
			int mid = (v[i+1] - v[i-1] + (i+1 == m+1 ? 0 : d-1))/d;

			int tot = left + right + mid;

			/*
			cout << endl << endl;
			cout << i << endl;
			cout << left << ' ' << right << ' ' << mid << endl;
			cout << "calc = " << tot << endl;
			*/

			if(tot <= best) {
				if(tot < best) qt = 0;
				best = tot;
				qt++;
			}
		}

		cout << best << ' ' << qt << '\n';
	}
}
