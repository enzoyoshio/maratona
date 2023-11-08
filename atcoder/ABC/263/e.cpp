#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 998244353;

int add(int a, int b) { return (a+b)%MOD;}
int sub(int a, int b) {
	return ((a-b)%MOD + MOD)%MOD;
}
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

	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i+1 < n; i++) cin >> v[i];

	vector dp(n, 0);

	for(int i = n-2; i >= 0; i--) {
		dp[i] = mul(sub(dp[i+1], dp[i+v[i]+1]), fexp(v[i]+1));
		dp[i] = add(dp[i], 1);
		int div = sub(1, fexp(v[i]+1));
		dp[i] = mul(dp[i], fexp(div));
		if(i) dp[i] = add(dp[i], dp[i+1]);	
	}
	cout << dp.front() << endl;
}
