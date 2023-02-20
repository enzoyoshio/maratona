#include <bits/stdc++.h>

using namespace std;

using tiii = tuple<int,int,int>;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for(auto& it: v) 
        cin >> it;

    vector<vector<int>> tempoM(n, vector<int>(m, -1));
    vector<vector<int>> tempoP(n, vector<int>(m, -1));
    vector<vector<pair<int,int>>> pai(n, vector<pair<int,int>>(m));
    queue<pair<int,int>> qMonster, qPlayer;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) 
            if(v[i][j] == 'A')
                qPlayer.emplace(i, j), pai[i][j] = {i,j}, tempoP[i][j] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(v[i][j] == 'M')
                qMonster.emplace(i, j), tempoM[i][j] = 0;

    vector<pair<int,int>> lado = {
        {0, -1},
        {0, +1},
        {-1, 0},
        {+1, 0},
    };

    auto bounded = [&](int i, int j) {
        return 0 <= i && i < n && 0 <= j && j < m;
    };

    while(qMonster.size()) {
        auto [x, y] = qMonster.front(); qMonster.pop();
        for(auto [i, j]: lado) {
            i += x, j += y;
            if(bounded(i, j) && tempoM[i][j] == -1 && v[i][j] != '#') {
                tempoM[i][j] = tempoM[x][y] +1;
                qMonster.emplace(i, j);
            }
        } 
    }

    while(qPlayer.size()) {
        auto [x, y] = qPlayer.front(); qPlayer.pop();
        for(auto [i, j]: lado) {
            i += x, j += y;
            if(bounded(i, j) && tempoP[i][j] == -1 && v[i][j] != '#') {
                tempoP[i][j] = tempoP[x][y] +1;
                qPlayer.emplace(i, j);
                pai[i][j] = {x, y};
            }
        } 
    }

    auto transform = [](pair<int,int> a, pair<int,int> b) {
        a.first -= b.first;
        a.second -= b.second;

        if(a.first == 1) return 'D';
        else if(a.first == -1) return 'U';
        else if(a.second == 1) return 'R';
        else return 'L';
    };

    auto rec = [&](int i, int j) {
        string ans = "";
        while(make_pair(i, j) != pai[i][j]) {
            
            if(tempoM[i][j] > -1 && tempoM[i][j] <= tempoP[i][j]) {
                return false;
            }
            ans += transform(make_pair(i, j), pai[i][j]);
            int poxa = pai[i][j].second;
            i = pai[i][j].first;
            j = poxa;
        } 
        reverse(ans.begin(), ans.end());
        cout << "YES\n";
        cout << ans.size() << endl;
        cout << ans << endl;
        return true;
    };

    for(int i = 0; i < n; i++) {
        if(v[i][0] == 'A' || v[i][m-1] == 'A')
            return cout << "YES\n0\n", 0;
        if(v[i][0] == '.' && pai[i][0] != make_pair(0, 0)) {
            // recupera path
            if(rec(i, 0)) 
                return 0;
        }
        if(v[i][m-1] == '.'&& pai[i][m-1] != make_pair(0, 0)) {
            // recupera pat
            if(rec(i, m-1))
                return 0;
        }
    }
    for(int j = 0; j < m; j++) {
        if(v[0][j] == 'A' || v[n-1][j] == 'A')
            return cout << "YES\n0\n", 0;
        
        if(v[0][j] == '.'&& pai[0][j] != make_pair(0, 0)) {
            // recupera path
            if(rec(0, j))
                return 0;
        }
        if(v[n-1][j] == '.'&& pai[n-1][j] != make_pair(0, 0)) {
            // recupera path
            if(rec(n-1, j))
                return 0;
        }
    }
    cout << "NO\n";
}
