#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n;
		cin >> n;
		vector<long long> v(n);
		for(auto& it: v)
			cin >> it;

		for(int i = 1; i < n; i++)
			v[i] += v[i-1];

		long long ans = v[n-2];

		for(int i = 1; i < n-1; i++)
			if(v[i]-v[i-1] == 0 && v[i-1]) ans++;

		cout << ans << endl;
	}
}
