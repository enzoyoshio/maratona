#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 998244353;

int add(int a, int b) { return (a+b)%MOD;}
int n, m;

int dp[1010][11][11][11];

int f(int idx, int lis1, int lis2, int lis3) {

	if(idx >= n)
		return lis3 < 1;

	auto& ans = dp[idx][lis1][lis2][lis3];

	if(~ans) return ans;
	ans = 0;

	for(int i = 0; i < m; i++) {
		if(i <= lis1) {
			ans = add(ans, f(idx+1, i, lis2, lis3));
		}else if((lis1 < i && i <= lis2)) {
			ans = add(ans, f(idx+1, lis1, i, lis3));
		}else if((lis2 < i && i <= lis3)) {
			ans = add(ans, f(idx+1, lis1, lis2, i));
		}
	}
	return ans;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	memset(dp, -1, sizeof dp);
	cin >> n >> m;
	cout << f(0, 10, 10, 10) << endl;
}
