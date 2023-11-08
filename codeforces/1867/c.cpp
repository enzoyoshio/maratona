#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {

	int t; cin >> t; while(t--) {
		int n;
		cin >> n;
		set<int> s;
		for(int i = 0; i < n; i++) {
			int a; cin >> a;
			s.insert(a);
		}

		// se n tiver 0
		if(s.find(0) == s.end()) {
			cout << 0 << endl;
			int q; cin >> q;
			continue;
		}

		int idx = 1;
		while(s.find(idx) != s.end()) idx++;
		cout << idx << endl;
		int q;
		while(cin >> q, q != -1) {
			cout << q << endl;
		}
	}
}
