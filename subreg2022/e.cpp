#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n, ans = 0; cin >> n;
    vector<int> v(1000010);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(v[x + 1]){
            v[x + 1]--;
            v[x]++;
        }else{
            v[x]++;
            ans++;
        }
    }
    cout << ans << "\n";
}
