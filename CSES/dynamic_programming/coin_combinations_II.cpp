#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1e9+7;
const int MAXN = 200;
int n, x;
vector<int> v;
/*
int tb[MAXN][1000010];

int dp(int idx, int peso) {

    if(peso == 0) return 1;
    if(idx >= n) return 0;

    int pega, npega = dp(idx+1, peso);

    if(peso - v[idx] >= 0) pega = dp(idx+1, peso-v[idx]);

    return (pega + npega)%MOD; 
}
*/

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> x;
    v.resize(n);
    for(auto& it: v) cin >> it;
    sort(v.begin(), v.end());

    vector<int> dp(x+1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= x; j++) {
            if(j-v[i] >= 0) dp[j] = (dp[j] + dp[j-v[i]])%MOD;
        }
    }

    cout << dp[x] << endl;
}
