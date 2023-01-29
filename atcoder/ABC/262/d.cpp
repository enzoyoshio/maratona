#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 998244353;
int n;
vector<int> v;
int tb[110][110][110][2];

int dp(int idx, int soma, int qtd, int mo, bool peguei=0) {

    if(peguei && soma == 0 && !qtd) return 1;

    if(idx >= n) return 0;

    auto& ans = tb[idx][soma][qtd][peguei];

    if(~ans) return ans;

    int pega = 0;
    int npega = 0;

    if(qtd) {
        pega = dp(idx+1, (soma+v[idx])%mo, qtd-1, mo, 1);
    }

    npega = dp(idx+1, soma, qtd, mo, peguei);

    return ans = (pega + npega)%MOD;

} 

signed main() {

    cin >> n;
    v.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];

    int ans = 0;
    
    for(int i = 1; i <= n; i++) {
        memset(tb, -1, sizeof tb);
        ans = (ans + dp(0, 0, i, i))%MOD;
    }
    
    cout << ans << endl;

}
