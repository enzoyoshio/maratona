#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> color;

bool bfs(int start) {

    queue<int> q;
    q.emplace(start);
    color[start] = 1;

    while(q.size()) {
        auto cur = q.front(); q.pop();

        for(auto f: g[cur]) {
            if(color[f] == color[cur]) return false;

            if(!color[f]) {
                if(color[cur] == 1) color[f] = 2;
                else color[f] = 1;
                q.push(f);
            }
        }
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    g.assign(n, vector<int>());

    while(m--) {
        int a, b; cin >> a >> b; a--, b--;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    color.assign(n, 0);
    
    for(int i = 0; i < n; i++) {
        if(!color[i] && !bfs(i)) 
            return cout << "IMPOSSIBLE\n", 0;
    }

    for(int i = 0; i < n; i++) 
        cout << (color[i] ? color[i] : 1) << ' ';
    cout << endl;
}
