#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<double> f(n+10, 0);

    for(int i = 1; i <= n; i++) {
        f[i] = 0;
        for(int idx = 1; idx <= 6; idx++) {
            f[i] += max((double)idx, f[i-1])/6.0;
        }   
    }

    cout << fixed << setprecision(13) << f[n] << endl;
}
