#include <bits/stdc++.h>

#define int long long

using namespace std;

const int oo = 1e15;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> dist(n, vector<int>(n, oo));

    for(int i = 0; i < n; i++) 
        dist[i][i] = 0;

    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c; a--, b--;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    for(int k = 0; k < n; k++) 
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        if(dist[a][b] == oo) cout << -1 << endl;
        else cout << dist[a][b] << endl;
    }
}
