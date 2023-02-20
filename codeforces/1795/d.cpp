#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MOD = 998244353;
const int MAXN = 5e5;
vector<int> fact(MAXN), invs(MAXN);

int fexp(int b, int e) {
    if(e == 0) return 1LL;

    int x = fexp(b, e/2);
    x = (x*x)%MOD;

    if(e%2) x = (x*b)%MOD;

    return x;
}

inline int inv(int n) { return fexp(n, MOD-2);}

int C(int n, int c) {
    return ((fact[n]*invs[c])%MOD * invs[n-c])%MOD;
}

int solve() {

    fact[0] = 1;
    for(int i = 1; i < MAXN; i++)
        fact[i] = (fact[i-1] * i)%MOD;

    for(int i = 0; i < MAXN; i++)
        invs[i] = inv(fact[i]);

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& it: v) 
        cin >> it;

    int groups = n/3;
    int ans = C(groups, groups/2);

    for(int i = 0; i < n; i += 3) {
        if(v[i] != v[i+1] && v[i+1] != v[i+2] && v[i] != v[i+2])
            continue;

        int miq = min({v[i], v[i+1], v[i+2]});
        int maq = max({v[i], v[i+1], v[i+2]});
        int fmiq = 0, fmaq = 0;
        for(int j = i; j < i+3; j++)
            fmiq += v[j] == miq, fmaq += v[j] == maq;
        if(fmaq == 2) continue;

        if(miq == maq) 
            ans = (ans*3)%MOD;
        else 
            ans = (ans*2)%MOD;
    }

    cout << ans << endl;
    return 0;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    while(t--)
        solve();
}
