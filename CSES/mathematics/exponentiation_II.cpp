#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int MOD = 1e9+7;
 
int fexp(int b, int e, int mod) {
    if(e == 0) return 1LL;
 
    int x = fexp(b, e/2, mod);
    x = (x*x)%mod;
 
    if(e%2) x = (x*b)%mod;
 
    return x;
}
 
signed main() {
    cin.tie(0)->sync_with_stdio(false);
 
    int n;
    cin >> n;
 
    for(int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        cout << fexp(a, fexp(b, c, MOD-1), MOD) << endl;
        // cout << fexp(fexp(a, b), c) << endl;
        // cout << fexp(a, fexp(b, c)) << endl;
    }
}
