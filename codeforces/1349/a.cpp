#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAXN = 200010;

vector<int> fact() {
	bitset<200010> a;
	a.set();
	vector<int> primes;
	a[0] = a[1] = 0;
	for(int i = 2; i < MAXN; i++) {
		if(a[i]) {
			primes.push_back(i);
			for(int j = i+i; j < MAXN; j+=i)
				a[j] = 0;
		}
	}
	return primes;
}

int fexp(int b, int e) {
	if(e == 0) return 1;

	int x = fexp(b, e/2);
	x = x*x;
	if(e%2) x *= b;
	return x;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n; 
	cin >> n;

	vector<int> v(n);
	for(auto& it: v) cin >> it;

	auto primes = fact();

	vector<vector<int>> exps(MAXN);

	for(auto it: v) {
		unordered_map<int,int> m;

		for(auto p: primes) {
			if(p > it) break;

			while(it%p == 0) {
				m[p]++;
				it /= p;
			}
		}

		for(auto [a, b]: m) {
			exps[a].push_back(b);
		}
	}

	int ans = 1;
	for(int i = 2; i < MAXN; i++) {
		if(exps[i].size() < n-1) continue;

		sort(begin(exps[i]), end(exps[i]));

		if(exps[i].size() == 1) ans *= fexp(i, *exps[i].begin());
		else ans *= fexp(i, *next(begin(exps[i])));
	}

	cout << ans << endl;

}
