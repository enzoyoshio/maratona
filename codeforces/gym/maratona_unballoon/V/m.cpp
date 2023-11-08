#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAXN = 1e7+3;

vector<int> p;

void build() {
	bitset<MAXN> a;
	a.set();
	a[0] = a[1] = 0;

	for(int i = 2; i < MAXN; i++) {
		if(a[i]) {
			p.push_back(i);
			for(int j = i+i; j < MAXN; j+=i)
				a[j] = false;
		}
	}
}

vector<pair<int,int>> fact(int n) {

	map<int,int> m;
	for(auto it: p) {
		if(it > n) break;

		while(n%it == 0) {
			n /= it;
			m[it]++;
		}
	}
	if(n > 1) m[n]++;
	vector<pair<int,int>> v;
	for(auto [a, b]: m) v.emplace_back(a, b);
	return v;
}

int tot_div = 0;

int ans(int idx, int resto, vector<pair<int,int>>& v) {

	if(idx >= v.size()) {
//		cout << resto << ' ' << tot_div << endl;
		return resto * tot_div;
	}

	int res = 0, p = 1;
	tot_div /= v[idx].second+1;
	for(int i = 0; i <= v[idx].second; i++) {
		tot_div *= (v[idx].second - i+1);
		res += ans(idx+1, resto * p, v);
		tot_div /= (v[idx].second - i+1);
		p *= v[idx].first;
	}
	tot_div *= v[idx].second +1;

	return res;
}

signed main() {
	int n; cin >> n;

	build();
	auto f = fact(n);

	tot_div = 1;
	for(auto [a, b]: f) tot_div *= (b+1);

	cout << ans(0, 1, f) << endl;
}
