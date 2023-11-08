#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9+7;
const int MAXN = 2e5;

vector<int> f(MAXN), inv(MAXN);

int add(int a, int b) { return (a+b)%MOD;}
int mul(int a, int b) { return (a*b)%MOD;}
int fexp(int b, int e=MOD-2) {
	if(e == 0) return 1LL;

	int x = fexp(b, e/2);
	x = mul(x, x);
	if(e%2) x = mul(x, b);
	return x;
}

int C(int n, int k) {
	return mul(f[n], mul(inv[k], inv[n-k]));	
}

signed main() {

	f[0] = 1;
	for(int i = 1; i < MAXN; i++)
		f[i] = mul(f[i-1], i);

	inv.back() = fexp(f.back());
	for(int i = MAXN-2; i >= 0; i--)
		inv[i] = mul(inv[i+1], i+1);

	int n, m;
	cin >> n >> m;

	map<int,int> exp;

	for(int i = 2; i*i <= m; i++) {
		while(m%i == 0) {
			exp[i]++;
			m /= i;
		}
	}
	if(m > 1) exp[m]++;

	int ans = 1;

	for(auto [a, b]: exp) {
		ans = mul(ans, C(b+n-1, b));
	}
	cout << ans << endl;
}

