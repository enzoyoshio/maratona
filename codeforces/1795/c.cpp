#include <bits/stdc++.h>

#define int long long

using namespace std;

int solve() {

    int n;
    cin >> n;
    vector<int> a(n), b(n), psum(n);
    for(auto& it: a) 
        cin >> it;
    for(auto& it: b)
        cin >> it;
    for(int i = 0; i < n; i++) {
        psum[i] = b[i];
        if(i) psum[i] += psum[i-1];
    }

    vector<int> times(n+10, 0), left(n+10, 0);

    for(int i = 0; i < n; i++) {
        int l = i, r = n-1, ans = n;

        while(l <= r) {
            int mid = (l+r) >> 1;

            if(psum[mid]-(i?psum[i-1]:0) > a[i]) ans = mid, r = mid-1;
            else l = mid+1;
        }
    
        // ans = first guy that a[i] cant reach
        // so consegue contribuir para o cara atual
        if(ans == i) {
            left[i] += a[i]%b[i];
        }else {
            times[i] += 1;
            times[ans] -= 1;
            left[ans] += a[i] - (psum[ans-1] - (i?psum[i-1]:0));
        }
    }

    for(int i = 1; i < n; i++) {
        times[i] += times[i-1];
    }

    for(int i = 0; i < n; i++) {
        cout << times[i]*b[i] + left[i] << ' ';
    }
    cout << endl;

    return 0;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}
