#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<pair<int,int>>> g(n);
    for(int i = 1; i < n; i++) {
        int a, b, w; cin >> a >> b >> w;
        a--, b--, w %= 2;
        g[a].emplace_back(b, w);
        g[b].emplace_back(a, w);
    }

    vector<int> ans(n, -1);
    queue<int> q;
    q.emplace(0);
    ans[0] = 0;

    while(q.size()) {
        auto cur = q.front(); q.pop();

        for(auto [u, d]: g[cur]) if(ans[u] == -1) {
            if(d) ans[u] = !ans[cur];
            else ans[u] = ans[cur];

            q.emplace(u);
        }
    }


    for(auto it: ans) cout << it << endl;
}
