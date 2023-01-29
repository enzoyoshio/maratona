#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(auto& it: v) cin >> it;

    int mn = *min_element(v.begin(), v.end());
    int total = n;

    while(k) {
        int curmn = 1e15;

        for(int i = 0; i < n; i++) {
            if(k-mn 
        }
    }

    int qt = n/k;
    cout << "qt = " << qt << endl;

    for(int i = 0; i < n; i++) {
        v[i] -= qt;
        v[i] = max(0LL, v[i]);
    }

    for(int i = 0; i < n%k; i++) {
        if(v[i] > 0) v[i]--;
    }

    for(auto it: v) cout << it << ' '; cout << endl;

}
