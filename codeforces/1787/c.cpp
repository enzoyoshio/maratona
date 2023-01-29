#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t; while(t--) {
        int n, s;
        cin >> n >> s;

        vector<int> v(n);
        vector<pair<int,int>> xy(n);

        for(auto& it: v) cin >> it;

        xy[0] = make_pair(v[0], v[0]);
        xy.back() = make_pair(v.back(), v.back());

        for(int i = 1; i < n-1; i++) {
            if(s == 0 || s >= v[i]) xy[i] = make_pair(0, v[i]);
            else {
                xy[i] = make_pair(s, v[i]-s);
                if(xy[i].first > xy[i].second) swap(xy[i].first, xy[i].second);
            }
        }

        vector<vector<int>> dp(n, vector<int>(2, 0));

        for(int i = 1; i < n; i++) {
        
            // 0 -> means that I am using (x, y) in the current pair
            // 1 -> means that I am using (y, x) in the current pair
            dp[i][0] = min(dp[i-1][0] + xy[i-1].second * xy[i].first,
                           dp[i-1][1] + xy[i-1].first * xy[i].first);

            dp[i][1] = min(dp[i-1][0] + xy[i-1].second * xy[i].second,
                           dp[i-1][1] + xy[i-1].first * xy[i].second);

        }

        cout << min(dp[n-1][0], dp[n-1][1]) << endl;
    }
}
