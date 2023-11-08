#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(auto& it: v) cin >> it;

	if(k == n) return cout << 1 << endl, 0;

	vector<int> ps(n);
	for(int i = 1; i < n; i++) {
		ps[i] = v[i] > v[i-1];
		if(i) ps[i] += ps[i-1];
	}

	int ct = 0;
	set<int> s;

	int ans = (ps[k-1] == k-1 ? 0 : 1);
	for(int i = 0; i < k; i++)
		s.insert(v[i]);

	for(int i = k; i < n; i++) {
		bool ok = v[i-k] == *begin(s) && v[i] > *rbegin(s);
		bool first = (ps[i] - ps[i-k+1]) == k-1;

		if(!ok && !first) ans++;
		if(first) ct++;

		s.erase(v[i-k]);
		s.insert(v[i]);
	}

	cout << ans + (ct != 0) << endl;
}
