#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t; while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n, -1);
        vector<int> p;
        for(int i = 1; i <= n/2; i++) 
            p.emplace_back(n+1 - i), 
            p.emplace_back(i);
        if(n%2) p.emplace_back((n+1)/2);

        int idx = 0;
        for(int i = 0; i < n; i++) {
            if(v[i] != -1) continue;

            v[i] = p[idx++];
            if(idx < n && i+k-1 < n && k > 1) v[i+k-1] = p[idx++]; 
        }

        for(auto it: v) cout<< it << ' '; cout << '\n';
    }
}
