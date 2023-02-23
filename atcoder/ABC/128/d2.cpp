#include <bits/stdc++.h>

#define int long long

using namespace std;

const int oo = 1e15;
int n, k;
vector<int> v;
int tb[55][55][110];

int dp(int l, int r, int moves) {
	
  	if(moves <= 0 || r < l) {
		return 0;
    }
  
  	auto& ans = tb[l][r][moves];
  
  	if(~ans) return ans;
  
  	int ret = 0;
  
  
    ret = max(ret, v[l] + dp(l+1, r, moves-1));
    //ret = max(ret, v[l] + dp(l+1, r, moves-1, 0, 1));
    //ret = max(ret, v[l] + dp(l+1, r, moves-1, 1, 0));
    ret = max(ret, dp(l+1, r, moves-2));
  
    ret = max(ret, v[r] + dp(l, r-1, moves-1));
    //ret = max(ret, v[r] + dp(l, r-1, moves-1, 1, 0));
    //ret = max(ret, v[r] + dp(l, r-1, moves-1, 0, 1));
    ret = max(ret, dp(l, r-1, moves-2));
  
  	return ans = ret;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);
  
  	memset(tb, -1, sizeof tb);
  
  	cin >> n >> k;
  	v.assign(n, 0);
  	for(int i = 0; i < n; i++)
      	cin >> v[i];
  	int ans = 0;
  	for(int i = 0; i <= k; i++)
      	ans = max(ans, dp(0, n-1, i));
  	cout << ans << endl;
}
