#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> a(n), b(m);
		int suma = 0;
		for(auto& it: a) cin >> it, suma += it;
		for(auto& it: b) cin >> it;
		sort(begin(a), end(a));
		sort(begin(b), end(b));

		k = (k%2 ? 1 : 2);

		multiset<int> aa(begin(a), end(a)), bb(begin(b), end(b));
		for(int i = 0; i < k; i++) {
			if(i == 0) {
				auto big = *rbegin(bb);
				auto small = *begin(aa);

				if(small <= big) {
					aa.insert(big);
					bb.insert(small);
					aa.erase(aa.find(small));
					bb.erase(bb.find(big));	
				}
			}else {
				auto big = *rbegin(aa);
				auto small = *begin(bb);

				if(small <= big) {
					bb.insert(big);
					aa.insert(small);
					bb.erase(bb.find(small));
					aa.erase(aa.find(big));	
				}
			}	
		}

		int ans = 0;
		for(auto el: aa) 
			ans += el;
		cout << ans << '\n';
		continue;
		if(k%2 == 0) {
			if(a.front() > b.back()) {
				cout << accumulate(begin(a), end(a), 0LL)
				- a.back() + b.front() << '\n';
			}else {
				cout << accumulate(begin(a), end(a), 0LL)
				<< '\n';
			}
		}else {
			if(a.front() > b.back()) {
				cout << accumulate(begin(a), end(a), 0LL) << '\n';
			}else {
				cout << accumulate(begin(a), end(a), 0LL) - a.front() + b.back() << '\n';
			}
		}
	}
}
