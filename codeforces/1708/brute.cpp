#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for(auto& it: v)
			cin >> it;

		while(v.size() > 1) {
			for(int i = 0; i+1 < n; i++)
				v[i] = v[i+1]-v[i];

			v.pop_back();
			sort(begin(v), end(v));
		}

		cout << *begin(v) << endl;
	}
}
