#include <bits/stdc++.h>

using namespace std;
#define int long long

int fexp(int b, int e, int mod) {
	if(e == 0) return 1LL;

	int x = fexp(b, e/2, mod);
	x = (x*x)%mod;
	if(e%2) x = (x*b)%mod;
	return x;
}

int compute(int i, int j, int m) {
	return (fexp(i, j, m) + fexp(j, i, m))%m;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for(auto& it: v) cin >> it;

	vector<bool> chosen(n);

	vector<vector<int>> tabelado(n, vector<int>(n));

	int a = 0, b = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j) continue;
			if(compute(v[i], v[j], m) > compute(v[a], v[b], m))
				a = i, b = j;

			tabelado[i][j] = compute(v[i], v[j], m);
		}
	}

	chosen[a] = 1;
	chosen[b] = 1;
	int ans = compute(v[a], v[b], m);

	for(int i = 2; i < n; i++) {

		int a = -1; b = -1;
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				if(!chosen[j] || chosen[k]) continue;

				if(a == -1 || tabelado[j][k] > tabelado[a][b]) a = j, b = k;
			}
		}
		chosen[a] = 1;
		chosen[b] = 1;
		ans += compute(v[a], v[b], m);
	}

	cout << ans << endl;

}
