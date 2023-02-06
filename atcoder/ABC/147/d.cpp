#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1e9+7;

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& it: v) cin >> it;
    vector<int> ans(63, 0);
    int res = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 61; j++) {
            int qt0 = i-ans[j];
            int qt1 = ans[j];
            if(((v[i]>>j)&1) != 0) {
                res = (res + ((1LL << j)%MOD*(qt0))%MOD)%MOD; 
                ans[j]++;
            }else {
                res = (res + ((1LL << j)%MOD*qt1)%MOD)%MOD;
            }
        }
    }
    cout << res << endl;
}

// 001
// 010
// 011
//
//  001
// +010
//
//  001
// +011
//
//  010
// +011
//
