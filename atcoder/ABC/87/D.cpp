#include <bits/stdc++.h>

#define int long long

using namespace std;

#define msg(x) cerr << x << endl
#define db(x) cerr << "[ " << #x << " ] = " << x << endl

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,int>> v(m);
    vector<vector<pair<int,int>>> toRight(n), toLeft(n);
    for(auto &[a, b, c]: v) {
        cin >> a >> b >> c;
        a--, b--;
        toRight[a].emplace_back(b, c);
        toLeft[b].emplace_back(a, c);
    }

    map<int,int> pos;
    vector<bool> vis(n, 0);
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            pos[i] = 0;
            queue<int> q;
            q.push(i);

            while(q.size()) {
                int idx = q.front(); q.pop();

                if(vis[idx]) continue;
                vis[idx] = 1;


                for(auto [dir, dist]: toRight[idx]) {
                    if(pos.find(dir) != pos.end() && pos[dir]-dist != pos[idx]) return cout << "No\n", 0;

                    pos[dir] = pos[idx]+dist;
                    q.push(dir);
                }

                for(auto [esq, dist]: toLeft[idx]) {
                    if(pos.find(esq) != pos.end() && pos[esq]+dist != pos[idx]) return cout << "No\n", 0;

                    pos[esq] = pos[idx]-dist;
                    q.push(esq);
                }
            }


        }
    }

    cout << "Yes\n";
    return 0;
}
