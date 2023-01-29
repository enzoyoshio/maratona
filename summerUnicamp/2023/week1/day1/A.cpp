#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = (1LL << 31)-1;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> s(n);
    for(auto &it: s) cin >> it;

    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<bool>> reach(n, vector<bool>(n, 0));

    dp[0][0] = 1;
    reach[0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(s[i][j] == '#') continue;


            if(i && s[i-1][j] != '#') {
                dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
                if(reach[i-1][j]) reach[i][j] = 1;
            }
            if(j && s[i][j-1] != '#') {
                dp[i][j] = (dp[i][j] + dp[i][j-1])%MOD;
                if(reach[i][j-1]) reach[i][j] = 1;
            }
        }
    }

    /*
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cout << dp[i][j] << ' '; cout << endl;
    }
    */

    if(reach[n-1][n-1]) cout << dp[n-1][n-1] << endl;
    else {

        queue<pair<int,int>> q;
        q.push(make_pair(0, 0));
        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        
        auto bounded = [&](int posx, int posy) {
            return posx >= 0 && posx < n && posy >= 0 && posy < n;
        };

        vector<pair<int,int>> lado = {
            {1, 0},
            {-1, 0},
            {0, 1},

            {0, -1}
        };

        while(q.size()) {
            auto [x, y] = q.front(); q.pop();

            vis[x][y] = 1;

            for(auto [i, j]: lado) if(bounded(x+i, y+j) && !vis[x+i][y+j] && s[i+x][j+y] == '.') {
                vis[x+i][y+j] = 1;
                q.push(make_pair(x+i, y+j));
            }
        }

        if(vis[n-1][n-1]) cout << "THE GAME IS A LIE\n";
        else cout << "INCONCEIVABLE\n";

    }
}
