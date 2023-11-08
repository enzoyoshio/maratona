#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e18;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];

	for(int i = 1; i < n; i++)
		v[i] += v[i-1];

	int small = -1, big = -1;
	int sumsm = oo, sumbg = 0;

	auto q = [&](int l, int r) {
		if(l == 0) return v[r];

		return v[r] - v[l-1];
	};

	for(int i = k-1; i < n; i++) {
		if(q(i-k+1, i) < sumsm)
			sumsm = q(i-k+1, i), small = i-k+1;	
		if(q(i-k+1, i) > sumbg)
			sumbg = q(i-k+1, i), big = i-k+1;
	}

	cout << small+1 << ' ' << big+1 << endl;
}
