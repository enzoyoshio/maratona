#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1e9 + 7;

signed main() {
    int n;
    cin >> n;
    vector<string> v(n);
    for(auto& line: v) cin >> line;

    if(n == 1) {
        if(v[0][0] == '*') cout << 0 << endl;
        else cout << 1 << '\n';
        return 0;
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(v[i][j] == '*') continue;

            if(i && v[i-1][j] != '*') dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
            if(j && v[i][j-1] != '*') dp[i][j] = (dp[i][j] + dp[i][j-1])%MOD;
        }
    }

    cout << dp.back().back() << endl; 
}
