#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
	int n;
	cin >> n;

	vector<int> f(n+10);

	for(int i = 1; i <= n; i++) {
		
			
		for(int j = 1; j*j <= i; j++) {
			if(i%j == 0) {
				f[i]++;
				if(j != i/j)
					f[i]++;
			}
		}
	}

	int ans = 0;

	for(int i = 1; i < n; i++) {
		ans += f[i] * f[n-i];
	}	

	cout << ans << endl;
}
