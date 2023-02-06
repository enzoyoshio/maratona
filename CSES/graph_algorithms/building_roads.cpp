#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }   

    vector<int> vis(n, 0);
    vector<int> path;
    int ans = 0;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            path.emplace_back(i+1);
            ans++;
            queue<int> q;
            q.emplace(i);
            vis[i] = 1;

            while(q.size()) {
                auto cur = q.front(); q.pop();

                for(auto fi: g[cur]) if(!vis[fi]) {
                    q.emplace(fi);
                    vis[fi] = 1;
                }
            }
        }       
    }

    cout << ans-1 << endl;
    for(int i = 1; i < path.size(); i++)
        cout << path[i-1] << ' ' << path[i] << endl;
}
