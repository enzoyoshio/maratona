#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	set<int> ans;
	set<int> a1;

	for(int i = 0; i < n; i++) {
		
		int a; cin >> a;

		set<int> novo;

		for(auto it: a1) {
			novo.insert(gcd(a, it));
			ans.insert(gcd(a, it));
		}

		novo.insert(a);
		ans.insert(a);

		a1 = novo;
	}

	cout << ans.size() << endl;
}
