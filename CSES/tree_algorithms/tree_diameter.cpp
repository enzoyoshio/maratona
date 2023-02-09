#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> g;

int main() {
    cin >> n;
    g.assign(n, vector<int>());

    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b; 
        a--, b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    queue<int> q;
    vector<int> vis(n, false);
    q.emplace(0);
    vis[0] = 1;
    int last = -1;

    while(q.size()) {
        auto cur = q.front(); q.pop();
        last = cur;

        for(auto el: g[cur]) if(!vis[el]) {
            q.emplace(el);
            vis[el] = 1;           
        }
    }

    q.emplace(last);
    fill(vis.begin(), vis.end(), -1);
    vis[last] = 0;

    while(q.size()) {
        auto cur = q.front(); q.pop();

        for(auto el: g[cur]) if(vis[el] == -1) {
            vis[el] = vis[cur] + 1;
            q.emplace(el);
        }
    }
    cout << *max_element(vis.begin(), vis.end()) << endl;
}
