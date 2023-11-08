#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9+7;

int add(int a, int b) { return (a+b)%MOD;}
int sub(int a, int b) { return ((a-b)%MOD + MOD)%MOD;}
int mul(int a, int b) { return (a*b)%MOD;}
int fexp(int b, int e=MOD-2) {
	if(e == 0) return 1LL;

	int x = fexp(b, e/2);
	x = mul(x, x);
	if(e%2) x = mul(x, b);
	return x;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	string s;
	cin >> s;
	vector<int> pref(256);
	vector suf(size(s), vector<int>(256));

	for(int i = (int)size(s) - 1; i >= 0; i--) {
		suf[i][s[i]]++;
		if(i < (int)size(s)-1)
			for(int j = 0; j < 256; j++)
				suf[i][j] += suf[i+1][j];
	}

	int ans = 0;
	for(int i = 0; i+1 < size(s); i++) {
		if(i && (s[i] == '?' || s[i] == 'B')) {
			ans = add(ans, mul(add(mul(pref['A'], fexp(3, pref['?'])), mul(pref['?'], fexp(3, pref['?']-1))), 
					   add(mul(suf[i+1]['C'], fexp(3, suf[i+1]['?'])), mul(suf[i+1]['?'], fexp(3, suf[i+1]['?']-1)))));
		}

		pref[s[i]]++;
	}

	cout << ans << endl;
}
