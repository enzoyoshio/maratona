#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, k;
vector<int> jew;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> k;
    jew.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> jew[i];

    int ans = 0;
    for(int l = 0; l < n; l++) {
        for(int r = 0; r < n; r++) {
            if(l+r > k || l+r > n) continue;
            
            vector<int> cur;
            for(int i = 0; i < l; i++)
                cur.push_back(jew[i]);
            for(int i = n-1, c = 0; c < r; i--, c++)
                cur.push_back(jew[i]);

            int qt = max(k-(l+r), 0LL);
            sort(cur.rbegin(), cur.rend());
            while(qt && cur.size() && cur.back() < 0) cur.pop_back(), qt--;
            ans = max(ans, accumulate(cur.begin(), cur.end(), 0LL));
        }
    }
    
    cout << ans << endl;
}
