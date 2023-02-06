#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
int n, x;
vector<pair<int,int>> v;
int tb[MAXN][100010];

int dp(int idx, int V) {
    if(idx >= n) return 0;

    int pega = 0;
    int npega = dp(idx+1, V);

    if(V-v[idx].first >= 0) pega = dp(idx+1, V-v[idx].first)+v[idx].second;
    return max(pega, npega);
}

int main() {
    cin >> n >> x;
    v.resize(n);
    for(auto& [a, b]: v) cin >> a;
    for(auto& [a, b]: v) cin >> b;

    for(int i = 0; i <= x; i++) tb[n][i] = 0;

    for(int idx = n-1; idx >= 0; idx--) {
        for(int peso = 0; peso <= x; peso++) {
            int npega = tb[idx+1][peso];
            int pega = 0;

            if(peso - v[idx].first >= 0) 
                pega = tb[idx+1][peso-v[idx].first] + v[idx].second;

            tb[idx][peso] = max(pega, npega);
        }
    } 

    cout << tb[0][x] << endl;
    /*
    vector<int> dp(x+10, 0);

    for(int weight = 0; weight <= x; weight++) {
        for(int idx = 0; idx < n; idx++) {
            if(weight - v[idx].first >= 0) 
                dp[weight] = max(dp[weight], dp[weight-v[idx].first]+v[idx].second);
        }
    }

    cout << dp[x] << endl;
    */
}
