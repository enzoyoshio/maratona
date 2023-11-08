#include <bits/stdc++.h>

using namespace std;
#define int  long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m, k;
	string s;
	cin >> n >> m >> k >> s;

	vector<int> psum(n);
	for(int i = 0; i < n; i++) {
		if(s[i] == 'x') psum[i]++;
		if(i) psum[i] += psum[i-1];
	}

	int res = 0;

}
