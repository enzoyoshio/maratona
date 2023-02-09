#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(auto& it: grid) 
        cin >> it;
    pair<int,int> start, finish;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'A')
                start = {i, j};
            if(grid[i][j] == 'B')
                finish = {i, j};
        }
    }


    auto bounded = [&](int i, int j) {
        return 0 <= i && i < n && 0 <= j && j < m;
    };

    vector<pair<int,int>> lado = {
        {-1, 0},
        {+1, 0},
        {0, -1},
        {0, +1},
    };

    vector<vector<pair<int,int>>> pai(n, vector<pair<int,int>>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int,int>> q;
    q.push(start);
    vis[start.first][start.second] = true;

    while(q.size()) {
        auto [x, y] = q.front(); q.pop();

        for(auto [i, j]: lado) {
            i+=x, j+=y;
            if(bounded(i, j) && grid[i][j] != '#' && !vis[i][j]) {
                pai[i][j] = {x, y};
                q.emplace(i, j);
                vis[i][j] = true;
            }
        }
    }

    if(!vis[finish.first][finish.second]) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    
    auto transform = [&](pair<int,int> cur, pair<int,int> p) {
        p.first -= cur.first;
        p.second -= cur.second;

        if(p.first == 1) return 'U';
        else if(p.first == -1) return 'D';
        else if(p.second == 1) return 'L';
        else return 'R';
    };

    string ans = "";
    while(finish != start) {
        ans += transform(finish, pai[finish.first][finish.second]);
        finish = pai[finish.first][finish.second];
    }
    reverse(ans.begin(),ans.end());
    cout << ans.size() << endl;
    cout << ans << endl;

}
