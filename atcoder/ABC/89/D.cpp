#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int h, w, d;
    cin >> h >> w >> d;
    vector<vector<int>> v(h, vector<int>(w));
    vector<pair<int, int>> coisa(h*w);
    vector<int> ans(h*w);

    for(auto& it: v) for(auto& el: it) cin >> el, el--;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            coisa[v[i][j]] = make_pair(i, j);
        }
    }

    for(int i = 0; i < d; i++) {
        ans[i] = 0;
        for(int j = i+d; j < h*w; j += d) {
            ans[j] = ans[j-d] + abs(coisa[j].first-coisa[j-d].first) + abs(coisa[j].second-coisa[j-d].second);
        }
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r; l--, r--;

        if(l < d) cout << ans[r] << endl;
        else cout << ans[r] - ans[l] << endl; 

    }
}
