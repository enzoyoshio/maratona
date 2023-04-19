#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n; cin >> n;
		vector<int> v(n);
		for(auto& it: v)
			cin >> it;
		
		bool yes = true;

		for(int i = 1; i < n; i++) {
			if(v[i]%v[i-1]) v[i] %= v[i-1];
			else v[i] = v[i-1];
		}

		for(int i = 1; i < n; i++)
			yes &= v[i]-v[i-1] == 0;

		cout << (yes ? "YES" : "NO") << endl;
	}
}
