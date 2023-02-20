#include <bits/stdc++.h>

#define int long long

using namespace std;

int solve() {
   
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& it: v) cin >> it;

    vector<int> qt2(n, 0);
    for(int i = 0; i < n; i++)
        qt2[i] = v[i] == 2;
    for(int i = 1; i < n; i++)
        qt2[i] += qt2[i-1];

    for(int i = 0; i < n-1; i++) {
        if(qt2[i] == qt2.back() - qt2[i]) {
            return cout << i+1 << endl, 0;
        }
    }
    cout << -1 << endl;
    return 0;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t=1;
    cin >> t;
    while(t--) 
        solve();
}
