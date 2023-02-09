#include <bits/stdc++.h>

using namespace std;
#define int long long

using tiii = tuple<int,int,int>;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, x;
    cin >> n >> x;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first; v[i].second = i;
    }

    sort(v.begin(), v.end());

    set<tiii> sum;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            auto p = sum.lower_bound(tiii{x-v[i].first-v[j].first, 0, 0});

            if(p != sum.end()) {
                auto [val, id1, id2] = *p;
                if(val == x-v[i].first-v[j].first) {
                    cout << v[i].second+1 << ' ' << v[j].second+1 << ' ' << id1+1 << ' ' << id2+1 << endl;
                    return 0;
                }
            }

        }
        for(int j = 0; j < i; j++) {
            sum.emplace(v[i].first+v[j].first, v[i].second, v[j].second);
        }
    }

    cout << "IMPOSSIBLE\n";
}
