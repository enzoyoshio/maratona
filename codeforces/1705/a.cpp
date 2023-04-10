#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; cin >> t; while(t--) {
		int n, x;
		cin >> n >> x;
		vector<int> v(2*n);
		for(auto& it: v)
			cin >> it;
		sort(begin(v), end(v));

		bool can = true;
		for(int i = 0; i < n; i++)
			can &= v[i]+x <= v[i+n];

		cout << (can ? "yes" : "no") << endl;
	}
}
