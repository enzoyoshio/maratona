#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 998244353;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, d;
	cin >> n >> d;
	vector<int> v(n);
	for(auto& it: v) cin >> it, it--;

	vector<int> ord(n);
	iota(begin(ord), end(ord), 0LL);

	int ans = 0;
	do {

		bool can;
		for(int i = 0; i < n; i++) {
			if(ord[i] - i > d 
			|| (~v[i] && v[i]-ord[i])) can = false;
		}

		ans += can;

		if(can >= MOD) can -= MOD;


	}while(next_permutation(begin(ord), end(ord)));
	cout << ans << endl;
}
