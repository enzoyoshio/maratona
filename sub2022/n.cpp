#include <bits/stdc++.h>

using namespace std;
#define int long long

// take thngs such that maximizes bi - ai
struct lbig {

	multiset<int> left, right;
	int sumL, sumAll, l;

	lbig(int l) : l(l), sumL(0), sumAll(0) {}

	int query() {
		return sumL + sumAll;
	}

	void add(int a, int b) {
		left.insert(b);
		sumL += b;
		sumAll += a;
		balancear();
	}

	void rem(int a, int b) {
		if(right.find(b) != right.end()) {
			right.erase(right.find(b));
		}else {
			left.erase(left.find(b));
			sumL -= b;
		}
		sumAll -= a;
		balancear();
	}

	void balancear() {

		while(left.size() > l) {
			auto b = *begin(left);
			sumL -= b;
			right.insert(b);
			left.erase(begin(left));
		}

		while(left.size() < l && right.size()) {
			auto b = *prev(end(right));
			sumL += b;
			left.insert(b);
			right.erase(prev(end(right)));
		}

	}

	int size() {
		return left.size() + right.size();
	}

};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(auto& it: a) cin >> it;
	for(auto& it: b) cin >> it;

	int k, l;
	cin >> k >> l;

	for(int i = 0; i < n; i++) {
		a.push_back(a[i]);
		b.push_back(b[i]);
	}

	lbig sset(l);

	int ans = 0;
	for(int i  = n-k; i < n+k; i++) {
		sset.add(a[i], b[i]);
		if(sset.size() > k) sset.rem(a[i-k], b[i-k]);
		if(sset.size() == k) ans = max(sset.query(), ans);
	}

	cout << ans << endl;
}
