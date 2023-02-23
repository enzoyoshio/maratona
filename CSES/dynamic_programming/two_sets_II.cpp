#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MOD = 1e9+7;
const int MAXN = 501;
int n, half;
int tb[MAXN][MAXN*(MAXN+1)/2];

int dp(int idx=1, int val=0) {

    if(idx > n) {
        return val == half;
    } 

    auto& ans = tb[idx][val];

    if(~ans) return ans;

    int pega = dp(idx+1, val+idx);
    int npega = dp(idx+1, val);

    return ans = (pega + npega)%MOD;
}

long long fexp(long long b, int e) {
    if(e == 0) return 1LL;

    long long x = fexp(b, e/2);
    x = (x*x)%MOD;
    if(e%2) x = (x*b)%MOD;
    return x;
}

signed main() {

    memset(tb, -1, sizeof tb);
    cin >> n;

    half = ((n*(n+1))%4 == 0 ? n*(n+1)/4 : -1);

    cout << ((long long)dp() * fexp(2, MOD-2))%MOD << endl;
}
