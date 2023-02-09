#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n+10), week(n);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }

    vector<int> pieces(n+10);
    for(int i = 1; i <= n; i++) {
        pieces[i] = a[i/2]*2 + (i%2 == 1 ? a[i/2+1]-a[i/2] : 0); 
    }

    vector<int> ans(n+10);
    for(int i = 1; i <= n; i++) {
        for(int j = 2; j <= n; j++) {
            if(i - j >= 0) ans[i] = max(ans[i], pieces[j-1] + ans[i-j]);
        }
    }
    cout << ans[n] << endl;
}
