#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n; cin >> n;
		vector<int> v(n);
		for(auto& it: v) cin >> it;

		if(*max_element(begin(v), end(v)) == *min_element(begin(v), end(v))) {
			cout << -1 << '\n';
			continue;
		}

		vector<int> f, s;
		sort(begin(v), end(v));

		f.push_back(v[0]);
		for(int i = 1; i < n; i++) {
			if(v[i] == v[0])
				f.push_back(v[i]);
			else 
				s.push_back(v[i]);
		}

		cout << f.size() << ' ' << s.size() << '\n';
		for(auto el: f) cout << el << ' '; cout << '\n';
		for(auto el: s) cout << el << ' '; cout << '\n';


	}
}
