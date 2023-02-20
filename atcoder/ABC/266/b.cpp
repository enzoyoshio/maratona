#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    const int mod = 998244353;

    cout << ((n-mod)%mod + mod)%mod << endl;
}
