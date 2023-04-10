#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
const int MAXN = 1e6;

string s;
int tb[MAXN][2];

int add(int a, int b) {
	return (a + b)%MOD;
}

int mul(int a, int b) {
	return ((long long)a * (long long)b)%MOD;
}

int fexp(int b, int e) {
	if(e == 0) return 1;

	int x = fexp(b, e/2);
	x = mul(x, x);

	if(e%2) x = mul(x, b);

	return x;
}

int dp(int idx, int prev) {


	auto& ans = tb[idx][prev];

	if(~ans) return ans;
	if(idx == (int)s.size()) return ans = 1;

	if(prev) return ans = fexp(3, (int)s.size()-idx);

	if(s[idx] == '0') ans = dp(idx+1, 0);
	else ans = add(mul(2, dp(idx+1, 0)), dp(idx+1, 1));	
	return ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	memset(tb, -1, sizeof tb);

	cin >> s;

	cout << dp(0, 0) << endl;
}
