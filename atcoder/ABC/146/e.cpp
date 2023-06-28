#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(auto& it: v) cin >> it;

	map<int,int> m;
	int ans = 0;

	int soma = 0;
	for(int i = 0; i < n; i++) {
		soma += v[i];

		cout << soma << ' ';
		if(soma%k == 0 && soma/k == i+1) ans++;

		ans += m[soma - k*i];
		m[soma - k*(i+1) + k]++;
	}
	cout << ans << endl;
}
