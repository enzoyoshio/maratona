#include <bits/stdc++.h>

using namespace std;

#define int long long

int solve() {

	int n;
	cin >> n;
	vector<vector<int>> v(2, vector<int>(n));
	v[0][0] = 2*n;
	v.back().back() = 2*n-1;

	int smaller = 1, greater = 2*n-2;

	for(int i = 1; i < n; i++) {
		if(i%2) v[0][i] = smaller, v[1][i-1] = smaller+1, smaller += 2;
		else v[1][i-1] = greater, v[0][i] = greater-1, greater -= 2; 
	}

	for(auto line: v) {
		for(auto el: line)
			cout << el << ' ';
		cout << endl;
	}

	return 0;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t=1;
	cin >> t;
	while(t--) solve();
}
