#include <bits/stdc++.h>

using namespace std;
#define int long long

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n; cin >> n;
		vector<int> a(n), b(n);
		for(auto& it: a) cin >> it;
		for(auto& it: b) cin >> it;

		if(*max_element(begin(a), end(a)) == 0 && *min_element(begin(a), end(a)) == 0) {
			cout << "Yes\n";
			continue;
		}
		
		/*
		if(a == b) {
			cout << "Yes\n";
			continue;
		}
		*/

		auto f = [](int big, int small) {
			int qt = big/small;
			return array<int, 3>{small, big%small, qt + (qt%2 ? qt/2 : (qt-1)/2)};
		};
	
		auto f2 = [](int big, int small) {
			int qt = big/small;
			return array<int, 3>{small, big%small, qt + (qt%2==0 ? qt/2 : (qt-1)/2)};
		};
			
		vector<int> ope(n), qt(3);

		for(int i = 0; i < n; i++) {
			while(b[i] && a[i]) {

				if(a[i] > b[i]) {
					auto [big, small, opes] = f(a[i], b[i]);
					a[i] = big;
					b[i] = small;
					ope[i] += opes;
				}else if(a[i] < b[i]) {
					auto [big, small, opes] = f2(b[i], a[i]);
					a[i] = big;
					b[i] = small;
					ope[i] += opes;

				}else {
					b[i] = 0;
					ope[i]++;
				}
			}

			//db(i);
			//db(ope[i]);
		}

		for(int i = 0; i < n; i++) {
			if(a[i] == 0 && b[i] == 0) continue;
			qt[ope[i]%3]++;
		}

		sort(begin(qt), end(qt));
		if(qt[0] || qt[1]) cout << "No\n";
		else cout << "Yes\n";
	}
}
