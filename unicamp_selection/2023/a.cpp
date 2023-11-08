#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t=1;
	while(t--) {
		int n; cin >> n;
		int sum = 0;
		for(int i = 1; i <= n; i++)
			sum += 2*i-1;
		cout << sum << endl;
	}
}
