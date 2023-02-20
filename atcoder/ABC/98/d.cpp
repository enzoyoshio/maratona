#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n), psum(n), xorsum(n);
    for(auto& it: v)
        cin >> it;
    for(int i = 0; i < n; i++) {
        psum[i] = xorsum[i] = v[i];
        if(i) psum[i] += psum[i-1], xorsum[i] += xorsum[i-1];
    }

    map<int,int> dd;
    int ans = 0;

    for(int i = 0; i < n; i++) {
        ans += dd[psum[i]-xorsum[i]];
        cout << psum[i] - xorsum[i] << '\n';
        dd[psum[i]-xorsum[i]]++;
    }

    cout << ans << endl;
}
