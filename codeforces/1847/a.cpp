#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n, k; cin >> n >> k;
		vector<int> v(n);
		for(auto& it: v) cin >> it;
		for(int i = 0; i+1 < n; i++) {
			v[i] = abs(v[i]-v[i+1]);
		}
		v.back() = 0;
		sort(rbegin(v), rend(v));
		for(int i = 0; i < k-1; i++) {
			v[i] = 0;
		}
		cout << accumulate(begin(v), end(v), 0) << '\n';
	}
}
