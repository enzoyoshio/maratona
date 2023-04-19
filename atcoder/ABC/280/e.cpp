#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
	return (a+b)%MOD;
}

int sub(int a, int b) {
	return ((a-b)%MOD + MOD) %MOD;
}

int mul(int a, int b) {
	return ((long long)a * (long long)b)%MOD;
}

int fexp(int b, int e=MOD-2) {
	if(e == 0) return 1;

	int x = fexp(b, e/2);
	x = mul(x, x);

	if(e%2)
		x = mul(x, b);

	return x;
}

int n, p;
map<tuple<int,int,int>, int> dp;

int tree(int life=n, int ans=1, int deg=0) {

	if(life <= 0)
		return mul(deg, ans);

	if(dp.find({life, ans, deg}) != dp.end()) return dp[{life, ans, deg}];

	return dp[{life, ans, deg}] = add(tree(life-2, mul(ans, p), deg+1) ,tree(life-1, mul(ans, sub(1, p)), deg+1));
}

int main() {
	cin >> n >> p;
	p = mul(p, fexp(100));

	vector<int> fact(n+10), inv(n+10);

	fact[0] = 1;
	for(int i = 1; i < fact.size(); i++) {
		fact[i] = mul(fact[i-1], i);
	}

	inv.back() = fexp(fact.back());
	for(int i = (int)inv.size()-2; i >= 0; i--) {
		inv[i] = mul(inv[i+1], i+1);
	}
	
	auto C = [&](int c, int k) {
		return mul(fact[c], mul(inv[k], inv[c-k]));
	};

	int ans = 0;

	for(int x = 0; 2*x <= n-1; x++) {
		int y = n-1-2*x;
		ans = add(ans, mul(add(add(1, x), y), mul(fexp(p, add(x, 1)), mul(fexp(sub(1, p), y), C(x+y, x)))));
	}

	for(int x = 0; 2*x <= n; x++) {
		int y = n-2*x;
		ans = add(ans, mul(add(x, y), mul(fexp(p, x), mul(fexp(sub(1, p), y), C(x+y, x)))));
	}

	cout << ans << endl;
}
