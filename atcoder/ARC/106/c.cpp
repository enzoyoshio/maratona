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
    
    vector<pair<int,int>> ans1, ans2;

    for(int t = 1; t <= taka; t++) {
        if(ans1.empty()) {
            ans1.emplace_back(2, 5);
        }else {
            ans1.emplace_back(ans.back().second + 2, ans.back().second + 5);
        }
    }

    for(int a = 1; a <= aoki; a++) {
        if(a == 1) {
            ans.emplace_back(1, ans[1].first+1);
        }else {
            ans.emplace_back(ans[2*(a-1)].first-1, ans[2*(a-1)+1].first+1); 
        }
    }

    for(auto [a, b]: ans) cout << a << ' ' << b << endl;
}
