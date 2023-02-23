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

    for(int i = 1; i < n; i++)
        v[i] += v[i-1];

    auto psum = [&](int l, int r) {
        if(!l) return v[r];

        return v[r] - v[l-1];
    };

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int l = i, r = n-1, target = -1;

        while(l <= r) {
            int mid = (l + r) >> 1;

            if(psum(i, mid) <= x) target = psum(i, mid), l = mid+1;
            else r = mid-1;
        } 

        ans += target == x;
    }

    cout << ans << endl;
}
