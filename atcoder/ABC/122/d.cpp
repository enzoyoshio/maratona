#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1e9+7;
int n;
string s = "ACGT";
int tb[110][5][5][5][5];

int dp(int idx, int a=0, int b=0, int c=0, int d=0) {
    
    if(idx > 2 && s[b] == 'A' && s[c] == 'G' && s[d] == 'C') return 0;
    if(idx > 2 && s[b] == 'G' && s[c] == 'A' && s[d] == 'C') return 0;
    if(idx > 2 && s[b] == 'A' && s[c] == 'C' && s[d] == 'G') return 0;
    if(idx > 3 && s[a] == 'A' && s[b] == 'G' && s[d] == 'C') return 0;
    if(idx > 3 && s[a] == 'A' && s[c] == 'G' && s[d] == 'C') return 0;

    if(idx >= n) return 1;

    auto& ans = tb[idx][a][b][c][d];

    if(~ans) return ans;

    int ret = 0;
    for(int i = 0; i < 4; i++)
        ret = (ret + dp(idx+1, b, c, d, i))%MOD;

    return ans = ret;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    memset(tb, -1, sizeof tb);
    cin >> n;
    cout << dp(0) << endl;
}
