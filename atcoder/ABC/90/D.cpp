#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    int ans = 0;
    const int MAXN = 2e5;

    if(k == 0) return cout << n*n << endl, 0;
    for(int i = k+1; i <= n; i++) {
        int cur = 0;
        int qts = n/i;
        ans += qts*(i-k);
        cur += qts*(i-k);
        int left = n%i;
        if(left >= k) ans += left-k+1, cur += left-k;
//        cout << "cur = " << cur << " i = " << i << endl;
    } 
    cout << ans << endl;
}
