#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> pai;

    DSU(int tam) {
        pai.assign(tam, 0);
        iota(pai.begin(), pai.end(), 0);
    }

    int find(int x) {
        return x == pai[x] ? x : pai[x] = find(pai[x]);
    }

    bool same_set(int x, int y) {
        return find(x) == find(y);
    }

    void join(int x, int y) {
        if(same_set(x, y)) return;

        x = find(x);
        y = find(y);

        pai[y] = x;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int h, w;
    pair<int,int> start, finish;
    cin >> h >> w >> start.first >> start.second >> finish.first >> finish.second;
    start.first--;
    start.second--;
    finish.first--;
    finish.second--;
    int st = start.first*w+start.second;
    int fi = finish.first*w+finish.second;

    vector<string> grid(h);
    for(auto& line: grid) 
        cin >> line;

    DSU dsu(h*w);
    vector<vector<int>> g(h*w);

    auto bounded = [&](int i, int j) {
        return 0 <= i && i < h && 0 <= j && j < w;
    };

    vector<pair<int,int>> lado = {
        {-1, 0},
        {+1, 0},
        {0, -1}, 
        {0, +1},
    };

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(grid[i][j] != '.') continue;
            for(auto [x, y]: lado) {
                x += i, y += j;
                if(bounded(x, y) && grid[x][y] == '.')
                    dsu.join(dsu.find(i*w + j), dsu.find(x*w + y));
            }
        }
    }
    
    if(dsu.same_set(st, fi)) 
        return cout << 0 << endl, 0;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(grid[i][j] != '.') continue;

            for(int k = i-2; k <= i+2; k++) {
                for(int l = j-2; l <= j+2; l++) {
                    if(bounded(k, l) && 
            !dsu.same_set(dsu.find(i*w+j), dsu.find(k*w+l)) &&
                       grid[k][l] == '.') {
                        int id1 = dsu.find(i*w+j);
                        int id2 = dsu.find(k*w+l);
                        g[id1].push_back(id2);
                        g[id2].push_back(id1);
                    }
                }
            }
        }
    }

    queue<int> q;
    q.emplace(dsu.find(st));
    vector<int> dist(h*w, -1);
    dist[q.front()] = 0;
    
    while(q.size()) {
        auto cur = q.front(); q.pop();

        for(auto u: g[cur]) if(dist[u] == -1) {
            dist[u] = dist[cur] + 1;
            q.emplace(u);
        }
    }

    cout << dist[dsu.find(fi)] << endl;
}
