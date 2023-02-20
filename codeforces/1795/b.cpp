#include <bits/stdc++.h>

#define int long long

using namespace std;

int solve() {
    int n, k;
    cin >> n >> k;
    map<int,int> left, right;
    for(int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        left[l]++;
        right[r]++;
    }

    if(left[k] > 0 && right[k] > 0) cout << "yes\n";
    else cout << "no\n";

    return 0;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}
