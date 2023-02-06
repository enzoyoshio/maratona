#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int MOD = 1e9+7;
const int MAXN = 1e6+10;
const int oo = MOD;
int n, x;
vector<int> v;
 
signed main() {
	cin >> n >> x;
	v.resize(n);
	for(int i = 0; i < n; i++) 
		cin >> v[i];
	
	
	vector<int> dp(MAXN, 0);
	dp[0] = 1;
	
	for(int i = 1; i < MAXN; i++) {
        dp[i] = 0;
		for(int money = 0; money < n; money++) {
			if(i - v[money] >= 0) dp[i] = (dp[i] + dp[i - v[money]])%MOD; 
		}
	}

    cout << dp[x] << endl;
}
