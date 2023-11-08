#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9+7;

int add(int a, int b) {
	return (a+b)%MOD;
}
int mul(int a, int b) {
	return (a*b)%MOD;
}
int fexp(int b, int e) {
	if(e == 0) return 1LL;
	int x = fexp(b, e/2);
	x = mul(x, x);
	if(e%2) x = mul(x, b);
	return x;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int sum = 0;
	for(int i = 1; i <= n; i++) {
		sum = add(sum, fexp(m, gcd(i, n)));
	}
}

// sum(m ** gcd(i, n)) / n
