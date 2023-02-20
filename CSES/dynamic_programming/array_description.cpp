#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1e9+7;
const int MAXN = 2e5;
int n, m;
vector<int> v(MAXN);
int tb[MAXN][110];

int dp(int idx, int prev) {
    
    if(v[idx] && abs(v[idx]-prev) > 1) return 0;
    if(idx >= n) return 1;

    auto& res = tb[idx][prev];
    if(~res) return res;

    int ans = 0;
    if(v[idx] == 0) {
        if(!idx) {
            for(int i = 1; i <= m; i++)
                ans = (ans + dp(idx+1, i))%MOD;
        }else {
            // posso escolher que numeros
            if(prev > 1) ans = (ans + dp(idx+1, prev-1))%MOD;
            if(prev+1 <= m) ans = (ans + dp(idx+1, prev+1))%MOD;
            ans = (ans + dp(idx+1, prev))%MOD;  
        }
    }else {
        if(abs(prev-v[idx]) > 1) ans = 0;
        else ans = dp(idx+1, v[idx]);
    }

    return res = ans;
}

signed main() {
    memset(tb, -1, sizeof tb);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << dp(0, v[0]) << endl;
}
