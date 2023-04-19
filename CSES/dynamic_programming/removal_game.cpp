#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MAXN = 5050;
int n;
vector<int> v;
int tb[MAXN][MAXN][2];

int dp(int l, int r, bool vez) {
	
	if(l == r) {
		if(vez) return v[l];
		return 0;
	}

	auto& ans = tb[l][r][vez];

	if(~ans) return ans;

	if(vez)
		ans = max(v[l] + dp(l+1, r, 0), v[r] + dp(l, r-1, 0));
	else 
		ans = min(dp(l+1, r, 1), dp(l, r-1, 1));
	return ans;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    v.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    memset(tb, -1, sizeof tb);

    cout << dp(0, n-1, 1) << endl;


}
