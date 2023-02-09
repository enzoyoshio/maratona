#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
const int MAXN = 2e5;
int n, m;
vector<int> v(MAXN);
int tb[MAXN][110];

int dp(int idx, int prev) {
    
    if(idx >= n) return 1;

    auto& res = tb[idx][prev];
    if(~res) return res;

    int ans = 0;
    if(v[idx] == 0) {
        // posso escolher que numeros
        if(prev > 1) ans = (ans + dp(idx+1, prev-1))%MOD;
        if(prev+1 <= m) ans = (ans + dp(idx+1, prev+1))%MOD;
        ans = (ans + dp(idx+1, prev))%MOD;  
    }else {
        if(abs(prev-v[idx]) > 1) return res = 0;
        ans = dp(idx+1, v[idx]);
    }

    return res = ans;
}

int main() {
    memset(tb, -1, sizeof tb);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int ans = 0;
    for(int i = 1; i <= m; i++)
        ans = (ans + dp(0, i))%MOD;
    cout << ans << endl;
}
