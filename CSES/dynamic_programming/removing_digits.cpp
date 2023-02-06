#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9;

int main() {
    int n; cin >>n;

    vector<int> dp(n+10, 0);

    for(int i = 0; i < 10; i++) dp[i] = 1;
    dp[0] = 0;

    for(int i = 10; i <= n; i++) {
        int cur = i;
        int ans = oo;

        while(cur) {
            int dig = cur%10; cur /= 10;
            if(dig && i-dig >= 0) ans = min(ans, dp[i-dig]+1); 
        }
        dp[i] = ans;
    }

    cout << dp[n] << endl;
}
