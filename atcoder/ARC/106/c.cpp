#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    // nao sei? 
    int taka=-1, aoki=-1;
    for(int i = 1; i <= n; i++) {
        int t = i, a = n-t;
        if((t-a) == m) {
            taka = t, aoki = a;
            break;
        }
    }

    if(taka == -1) return cout << -1 << endl, 0;

    // construir o algoritmo aqgora
    
    vector<pair<int,int>> ans;

    for(int t = 1; t <= taka; t++) {
        if(ans.empty()) {
            ans.emplace(2, 3);
        }else {
            ans.emplace(ans.back().second + 1, ans.back() + 2);
        }
    }

    for(int a = 1; a <= aoki; a++) {
        if(a == 1) {
            ans.emplace(1, ans.back().second+1);
        }else {
            
        }
    }

    for(auto [a, b]: ans) cout << a << ' ' << b << endl;
}
