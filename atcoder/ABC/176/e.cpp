#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int h, w, m; cin >> h >> w >> m;

    vector<pair<int,int>> hs(h, make_pair(0, 0)), ws(w, make_pair(0, 0));
    for(int i = 0; i < h; i++) hs[i].second = i;
    for(int i = 0; i < w; i++) ws[i].second = i;
    set<pair<int,int>> points;

    while(m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        hs[a].first++;
        ws[b].first++;
        points.emplace(a, b);
    }

    sort(hs.rbegin(), hs.rend());
    sort(ws.rbegin(), ws.rend());

    cout << hs.begin()->first + ws.begin()->first - (points.find(make_pair(hs.begin()->second, ws.begin()->second)) != points.end() ? 1 : 0) << endl;

    
}
