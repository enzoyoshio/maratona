#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e15;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for(auto& it: v) cin >> it;

	if(n%2 == 0) {

		vector<int> f(2, 0);
		for(int i = 0; i < n; i++) {
			f[i%2] += v[i];
		}
		cout << *max_element(begin(f), end(f)) << endl;
		return 0;
	}

	vector<int> maxpref(begin(v), end(v)), maxsuf(begin(v), end(v));

	for(int i = 1; i < n; i++)
		maxpref[i] = max(maxpref[i], maxpref[i-1]);
	for(int i = n-2; i >= 0; i--)
		maxsuf[i] = max(maxsuf[i], maxsuf[i+1]);

	vector<int> psum(begin(v), end(v));
	for(int i = n-3; i >= 0; i--) {
		psum[i] += psum[i+2];
	}

	int ans = -oo;
	int k = n/2-1;
	cout << k << endl;
	for(int i = 0; i+k+k-1 <= n; i++) {
		cout << " i = " << i << endl;

		int cur = psum[i];
		int aux = -oo;

		if(i + 2*k < n) cur -= psum[i+2*k], aux = max(aux, maxsuf[i+2*k]);

		if(i-2 >= 0) aux = max(aux, maxpref[i-2]);
		ans = max(ans, cur + aux);
	}

	cout << ans << endl;
}
