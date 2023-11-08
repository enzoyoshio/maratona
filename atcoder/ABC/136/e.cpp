#include <bits/stdc++.h>

using namespace std;
#define int long long

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"

vector<int> divi(int n) {
	vector<int> v;

	for(int i = 1; i*i <= n; i++) {
		if(n%i == 0) {
			v.push_back(i);
			if(i*i != n) v.push_back(n/i);
		}
	}

	sort(begin(v), end(v));
	return v;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(auto& it: v) cin >> it;

	int sum = accumulate(begin(v), end(v), 0LL), ans = 1;

	auto divs = divi(sum);

	auto check = [&](int x) {

		int negs = 0, pos = 0;

		for(auto el: v) {
			if(el%x < (x-el%x)) {
				negs += el%x;
			}else {
				pos += x-el%x;
			}
		}

		db(x);
		db(pos); 
		db(negs);
		

		while(max(pos, negs) > k && max(pos, negs) - min(pos, negs) > x) {
			int ma = max(pos, negs);
			int mi = min(pos, negs);
			ma -= x;
			pos = ma;
			negs = mi;
		}

		return abs(pos-negs)%x == 0 && max(pos, negs) <= k;
	};

	for(auto d: divs) {
		if(check(d)) ans = d;
	}

	cout << ans << endl;
}
