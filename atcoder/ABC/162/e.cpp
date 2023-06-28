#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9+7;

int add(int a, int b) { return (a+b)%MOD;}
int sub(int a, int b) { return ((a-b)%MOD+MOD)%MOD;}
int mul(int a, int b) { return (a*b)%MOD;}
int fexp(int b, int e = MOD-2) {
	if(e == 0) return 1LL;

	int x = fexp(b, e/2);
	x = mul(x, x);
	if(e%2) x = mul(x, b);
	return x;
}

signed main() {
	int n, k;
	cin >> n >> k;
	vector<int> ans(k+1);

	int res = 0;
	for(int i = k; i; i--) {
		ans[i] = fexp(k/i, n);

		for(int j = 2*i; j <= k; j += i)
			ans[i] = sub(ans[i], ans[j]);

		res = add(res, mul(ans[i], i)); 
	}
	cout << res << endl;
}
