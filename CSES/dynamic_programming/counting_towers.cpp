#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
const int MAXN = 1e6+8;

int n;
int tb[MAXN][10];

int add(int a, int b) {
	return (a + b)%MOD;
}

int dp(int idx=0, int pos=2) {

	if(idx >= n) {
		return pos == 2 || pos == 5;
	}

	auto& ans = tb[idx][pos];

	if(~ans) 
		return ans;

	int res = 0;

	if(pos == 0) {
		res = dp(idx+1, 2);
		res = add(res, dp(idx+1, 0));
	}else if(pos == 1 || pos == 3 || pos == 4) {
		res = dp(idx+1, 1);
		res = add(res, dp(idx+1, 3));
		res = add(res, dp(idx+1, 4));
		res = add(res, dp(idx+1, 5));	
	}else {
		for(int i = 0; i < 6; i++) {
			res = add(res, dp(idx+1, i));
		}
	}

	return ans = res;

}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	for(int i = 0; i < 6; i++)
		tb[0][i] = 0;
	tb[0][2] = tb[0][5] = 1;

	for(int idx = 1; idx < MAXN; idx++) {
		for(int pos = 0; pos < 6; pos++) {
			auto& ans = tb[idx][pos];
			ans = 0;
			if(pos == 0) {
				ans = add(ans, tb[idx-1][2]);
				ans = add(ans, tb[idx-1][0]);
			}else if(pos == 1 || pos == 3 || pos == 4) {
				ans = add(ans, tb[idx-1][1]);
				ans = add(ans, tb[idx-1][3]);
				ans = add(ans, tb[idx-1][4]);
				ans = add(ans, tb[idx-1][5]);
			}else {
				for(int i = 0; i < 6; i++)
					ans = add(ans, tb[idx-1][i]);
			}
		}
	}

	int t; cin >> t; while(t--) {
		cin >> n;
		cout << tb[n][2] << endl;
	}	
}
