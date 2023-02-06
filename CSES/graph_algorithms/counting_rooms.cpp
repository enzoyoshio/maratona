#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> pai;
    
    DSU(int n) {
        pai.assign(n, 0);
        iota(pai.begin(), pai.end(), 0);
    }

    int find(int x) {
        return x == pai[x] ? x : pai[x] = find(pai[x]);
    }

    void join(int a, int b) {
        a = find(a);
        b = find(b);

        if(a == b) return;
        
        pai[b] = a;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for(auto& line: v) cin >> line;

    DSU dsu(n*m);

    vector<pair<int,int>> lado = {
        {-1, 0},
        {+1, 0},
        {0, -1},
        {0, +1}
    };

    auto bounded = [&](int i, int j) {
        return 0 <= i && i < n && 0 <= j && j < m;
    };

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == '#') continue;
        
            for(auto [x, y]: lado) {
                x += i, y += j;
                if(bounded(x, y) && v[x][y] != '#') {
                    dsu.join(x*m+y, i*m+j);
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == '.' && dsu.find(i*m+j) == i*m+j) ans++;
        }
    }

    cout << ans << endl;
}
