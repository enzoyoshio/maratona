#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n, q;
    cin >> n >> q;
    vector<string> ler(n);
    for(auto& it: ler) cin >> it;
    vector<vector<int>> grid(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            grid[i][j] = ler[i][j] == '*';

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i) grid[i][j] += grid[i-1][j];
            if(j) grid[i][j] += grid[i][j-1];
            if(i && j) grid[i][j] -= grid[i-1][j-1];
        }
    }

    auto query = [&](int x1, int y1, int x2, int y2) {
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);

        int ans = grid[x2][y2];
        if(x1) ans -= grid[x1-1][y2];
        if(y1) ans -= grid[x2][y1-1];
        if(x1 && y1) ans += grid[x1-1][y1-1];
        return ans;
    };

    while(q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;

        cout << query(x1, y1, x2, y2) << endl;
    }
}
