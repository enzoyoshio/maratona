#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n, x, y; cin >> n >> x >> y;
    int tgt = 1LL << (n - 1), a = 1LL << n;
    int ans = 0;
    while(x != tgt){
        ans++;
        if(x < tgt){
            x = 2 * x;
        }else{
            x = 2 * x - a;
        }
    }
    cout << ans << "\n";
}
