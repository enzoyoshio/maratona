#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n; 
		cin >> n;
		vector<int> a(n), b(n);
		for(auto& it: a) cin >> it;
		for(auto& it: b) cin >> it;

		int sumA = accumulate(begin(a), end(a), 0LL);
		int sumB = accumulate(begin(b), end(b), 0LL);
		sort(begin(a), end(a));
		sort(begin(b), end(b));

		cout << min(b.front()*n+sumA, a.front()*n+sumB) << endl;
	}
}
