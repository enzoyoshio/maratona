#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for(auto& it: v)
		cin >> it;

	vector<int> a(n+2, -1);

	for(int i = 4; i < n; i++) {
		if(v[i-2] - v[i-3] > v[i])
			return cout << "No\n", 0;
	}
	for(int i = 0; i < n; i++) {
		if(i == 0) {
			a[0] = v[0]/3 + v[0]%3;
			a[1] = a[2] = v[0]/3;
		}else {
			if(v[i] - a[i] - a[i+1] < 0)
				return cout << "No\n", 0;
			a[i+2] = v[i] - a[i] - a[i+1];
		}
	}

	cout << "Yes\n";
	for(auto it: a)
		cout << it << ' ';
	cout << endl;
}
