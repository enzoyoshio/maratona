#include <bits/stdc++.h>

#define int long long

using namespace std;

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> ans(n, -2);

	for(int i = 0; i < n; i++) {
		int qt = n-i;

		// se todos os subarrays que comecam em i
		// podem ser positivos, entao eu deixo eles positivos
		if(k - qt >= 0) {
			ans[i] = 1000;
			k -= qt;
		}else {
			// se nao, eu tenho que deixar so x deles positivos e o resto negativo
			ans[i] = 2*k - 1;
			break;
		}
	}

	for(auto it: ans) 
		cout << it << ' ';
	cout << endl;
}

signed main() {
	//cin.tie(0)->sync_with_stdio(false);

	int t=1;
	cin >> t;
	while(t--) solve();
}
