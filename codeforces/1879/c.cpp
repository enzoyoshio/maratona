#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 998244353;
const int MAXN = 2e5+8;

int add(int a, int b) { return (a+b)%MOD;}
int mul(int a, int b) { return (a*b)%MOD;}
int fexp(int b, int e=MOD-2) {
	if(e == 0) return 1LL;

	int x = fexp(b, e/2);
	x = mul(x, x);
	if(e%2) return mul(x, b);
	return x;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	vector<int> f(MAXN);
	f[0] = 1;
	for(int i = 1; i < MAXN; i++)
		f[i] = mul(f[i-1], i);

	int t; cin >> t; while(t--) {
		string s;
		cin >> s;
		int n = s.size();
		int ff = 0, ss = 0;
		for(int i = 1; i < size(s); i++)
			ff += s[i] == s[i-1];

		vector<int> qt(size(s), 1);

		for(int i = 1; i < n; i++) {
			if(s[i] == s[i-1]) qt[i] = qt[i-1] + 1;
		}

		int groups = 0;

		int all = 1;
		for(int i = 0; i+1 < n; i++) {
			if(s[i] != s[i+1] && qt[i] > 1) {
				groups++;
				ss += qt[i];
				all = mul(all, qt[i]);
			}
		}

		if(qt.back() > 1) {
			groups++, ss += qt.back();
			all = mul(all, qt.back());
		}

		cout << ff << ' ' << mul(all, f[ss-groups]) << endl;
	}
}
