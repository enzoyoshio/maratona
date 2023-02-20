#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    const int oo = 1000;
    vector<pair<int,int>> v(4);
    for(auto& [a, b]: v)
        cin >> a >> b;

    for(int teste = 0; teste < 4; teste++) {
        int minx = oo, maxx = -oo, miny = oo, maxy = -oo;

        for(int i = 0; i < 4; i++) {
            if(i == teste) continue;
            minx = min(minx, v[i].first);
            miny = min(miny, v[i].second);
            maxx = max(maxx, v[i].first);
            maxy = max(maxy, v[i].second);
        }

        auto [a, b] = v[teste];
        if(minx < a && a < maxx && miny < b && b < maxy) { 
            cout << a << ' ' << b << endl;
            cout << minx << ' ' << maxx << endl;
            cout  << miny << ' ' << maxy << endl;
            return cout << "No\n", 0; 
        }
    }
    cout << "Yes\n";
}
