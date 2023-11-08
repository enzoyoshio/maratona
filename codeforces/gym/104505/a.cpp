#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9+7;

int add(int a, int b) { return (a+b)%MOD;}
int mul(int a, int b) { return (a*b)%MOD;}
int fexp(int b, int e=MOD-2) {
	if(e == 0) return 1LL;

	int x = fexp(b, e/2);
	x = mul(x, x);
	if(e%2) x = mul(x, b);
	return x;
}

signed main() {
	int n, k;
	cin >> n >> k;

	int num = 0, den = 0;
	for(int side = 1; side <= n; side++) {
		num = add(num, mul(fexp(side, k), fexp(n-side+1, k)));
		den = add(den, fexp(n-side+1, k));
	}

	cout << mul(num, fexp(den)) << endl;
}
