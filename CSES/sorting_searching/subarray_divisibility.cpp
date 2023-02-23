#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& it: v)
        cin >> it;

    v[0] = (v[0]%n + n)%n;
    for(int i = 1; i < n; i++) {
        v[i] += v[i-1];
        v[i] = (v[i]%n +n)%n;
    }

    map<int,int> mp;
    mp[0]++;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += mp[v[i]];
        mp[v[i]]++;
    }
    cout << ans << endl;
}
