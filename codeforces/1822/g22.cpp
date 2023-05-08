#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n;
		cin >> n;
		unordered_map<int,int> f;
		f.reserve(n);

		for(int i = 0; i < n; i++) {
			int a; cin >> a;
			f[a]++;
		}

		int ans = 0;
		for(auto [a, b]: f) {

			ans += b*(b-1)*(b-2);
			
			if(a > (int)1e6) {
				for(int i = 2; i <= 1000; i++) {
					if(a%i) continue;
					if(!f.contains(a*i) || !f.contains(a/i)) continue;
					ans += b * f[a/i] * f[a*i];
				}
			}else {
				for(int i = 1; i*i <= a; i++) {
					if(a%i) continue;
					if(i > 1 && f.contains(a/i) 
					&& f.contains(a*i)) {
						ans += b * f[a/i] * f[a*i];
					}
					int d = a/i;
					if(d != i && f.contains(a/d)
					&& f.contains(a*d))
						ans += b*f[a/d] *f[a*d];
				}
			}
		}
		cout << ans << endl;
	}
}
