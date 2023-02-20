#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> in(n);
    vector<vector<int>> g(n, vector<int>());

    while(m--) {
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        in[b]++;
    }

    queue<int> q;
    for(int i = 0; i < n; i++)
        if(!in[i]) 
            q.emplace(i);

    vector<int> ans;

    while(q.size()) {
        auto cur = q.front(); q.pop();
        ans.emplace_back(cur+1);
        for(auto u: g[cur]) {
            in[u]--;
            if(!in[u])
               q.emplace(u); 
        }
    }

    if((int)ans.size() != n) cout << "IMPOSSIBLE";
    else 
        for(auto el: ans)
            cout << el << ' ';
    cout << endl;
}
