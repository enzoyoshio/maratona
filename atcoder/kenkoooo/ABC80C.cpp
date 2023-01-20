#include <bits/stdc++.h>

using namespace std;

#define int long long
const int oo = 1e18;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> f(n, vector<int>(10)),
                        p(n, vector<int>(11));
    
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < 10; j++) 
            cin >> f[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 11; j++)
            cin >> p[i][j];

    int ans = -oo;
    for(int bit = 1; bit < (1LL << 10); bit++) {
        vector<int> soma(n, 0);

        for(int i = 0; i < n; i++) {
            int cur = 0;
            for(int j = 0; j < 10; j++) {
                if(f[i][j] && ((1LL << j)&bit) != 0) cur++;
            }
            soma[i] = cur;
        }
        
        int cur = 0;
        for(int i = 0; i < n; i++) 
            cur += p[i][soma[i]];

        ans = max(ans, cur);
    }
    cout << ans << endl;
}
