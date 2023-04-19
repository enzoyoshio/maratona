#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;

	if(n == 0) {
		cout << 1 << endl;
		return 0;
	}

	vector<int> v(n+1);
	for(auto& it: v)
		cin >> it;

	for(int i = 0; i < n; i++)
		if(v[i] >= (1 << i)) return cout << -1 << endl, 0;
	if(v.back() >= (1 << n)) return cout << -1 << endl, 0;

	int qt = v.back();
	int ans = v.back();

	for(int i = n-1; i >= 0; i--) {
		cout << "------------------------------------------------------------------------------------\n";

		if(i <= 31) {
			if(qt + v[i] <= (1 << i)) {
				cout << "no nivel " << i << " to adicionando " << qt << " mais " << v[i] << " na resposta\n";
				ans += qt + v[i];
			}
			else {
				cout << "no nivel " << i << " to adicionando " << (1 << i) << endl;
				ans += (1 << i);
			}

			if(i && qt + v[i] <= (1 << (i-1))) qt += v[i];
		}else {
			cout << "no nivel " << i << " to adicionando " << qt << " mais " << v[i] << " na resposta\n";
			ans += qt;
			ans += v[i];
			qt += v[i];
		}
	}
	cout << ans << endl;
}
