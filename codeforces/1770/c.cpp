#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int t; cin >> t; while(t--) {
        int n, even = 0;
        cin >> n;
        vector<int> v(n);
        for(auto& it: v) cin >> it, even += (it%2==0);
        sort(v.begin(), v.end());

        bool eq = 0;
        for(int i = 0; i+1 < n; i++) 
            eq |= v[i] == v[i+1];

        if(eq) {
            cout << "NO\n";
            continue;
        }

        if(even >= n-1 || even <= 2) {
            cout << "Yes\n";
            continue;
        }

        vector<int> g;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                g.push_back(gcd(v[i], v[j]));
            }
        }

        bool can = 1;
        for(int i = 0; i < g.size(); i++) {
            for(int j = i+1; j < g.size(); j++) {
                if(gcd(g[i], g[j]) != 1) can = 0;
            }
        }
        if(can) cout << "yes\n";
        else    cout << "NO\n";

    }
}
