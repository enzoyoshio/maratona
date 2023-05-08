#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
	int n;
	cin >> n;

	if(n == 1) {
		cout << 1 << endl;
		return;
	}

	if(n%2) {
		cout << -1 << endl;
		return;
	}

	vector<int> odd, even;

	for(int i = n; i; i-= 2)
		even.push_back(i);

	for(int i = 1; i < n; i += 2)
		odd.push_back(i);

	for(int i = 0; i < (int)even.size(); i++)
		cout << even[i] << ' ' << odd[i] << ' ';

	cout << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t=1;
	cin >> t;
	while(t--) solve();
}
