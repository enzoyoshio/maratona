#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int l, r;
		cin >> l >> r;

		int a=-1, b = -1;

		// se o range for maior q 1
		if(r-l+1 > 1) {
			if(r%2) r--;

			if(r != 2) a = r/2, b = r/2;
		}else {
			// se so tiver um cara
			if(r%2) {
				for(int i = 2; i*i <= r; i++) {
					if(r%i == 0) {
						a = i, b = r-i;
						break;
					}
				}
			}else if(r > 2) a = r/2, b = r/2;
		}

		if(a != -1 && gcd(a, b) > 1) 
			cout << a << ' ' << b << '\n';
		else cout << -1 << '\n';
	}
}
