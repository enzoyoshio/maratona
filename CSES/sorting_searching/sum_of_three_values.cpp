#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int n, x;
    cin >> n >> x;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i].first, v[i].second = i;
    sort(v.begin(), v.end());

    set<pair<int,int>> soma;
    for(int i = n-1; i >= 0; i--) {
        for(int j = i-1; j >= 0; j--) {
            auto p = soma.lower_bound(make_pair(x-v[i].first-v[j].first, 0));
            if(p != soma.end() && p->first == x-v[i].first-v[j].first) {
                cout << p->second+1 << ' ' << v[i].second+1 << ' ' << v[j].second+1 << endl;
                return 0;
            }
        }
        soma.emplace(v[i].first, v[i].second);
    }

    cout << "IMPOSSIBLE\n";
}
