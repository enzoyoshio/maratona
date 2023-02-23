#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(auto& it: v)
        cin >> it;

    for(int i = 1; i < n; i++) {
        v[i] += v[i-1];
    }

    map<int,int> mp;
    mp[x]++;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += mp[v[i]];
        mp[x+v[i]]++;
    }
    cout << ans << endl;
}
