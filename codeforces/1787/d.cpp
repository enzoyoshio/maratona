#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
vector<int> v;
vector<int> pai;
vector<vector<int>> G;
vector<int> funcional;
vector<int> vis;
vector<int> visPai;
vector<int> root;

void parent(int u) {
    visPai[u] = 1;
    pai[u] = 1;
    for(auto p: G[u]) {
        if(!visPai[p]) 
            parent(p);
        pai[u] += pai[p];
    }
}

void has_cycle(int u) {
    
    if(u == n) {
        vis[u] = 1;
        return;
    }

    // means that I'm processing
    // this vertice now
    vis[u] = 2; 

    bool has = false;
    // means that I found myself 
    // or I found a path
    // leading to a cycle
    // either way
    // this path leads to a cycle
    if(vis[funcional[u]] == 2) {
        vis[u] = 2;
        return; 
    }

    // if my son is not visited yet
    if(!vis[funcional[u]]) {
        has_cycle(funcional[u]);
    }

    vis[u] = vis[funcional[u]];
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t; while(t--) {
        cin >> n;
        v.assign(n, 0);
        pai.assign(n, 0);
        G.assign(n, vector<int>());
        vis.assign(n+1, 0);
        visPai.assign(n+1, 0);
        funcional.assign(n+1, 0);
        root.assign(n+1, -1);
        for(auto& it: v) cin >> it;

        auto bounded = [&](int x) {
            return 0 <= x && x < n;
        };

        // calcula ciclos
        for(int i = 0; i < n; i++) { 
            if(bounded(i+v[i])) funcional[i] = i+v[i];
            else funcional[i] = n;
        }

        for(int i = 0; i < n; i++) 
            if(!vis[i]) has_cycle(i);

        for(int i = 0; i < n; i++) {
            //cout << "has cycle in " << i << " ? " << vis[i] << endl;
        }

        // checking parent
        for(int i = 0; i < n; i++) {
            if(bounded(i + v[i])) G[i+v[i]].push_back(i);
        }

        for(int i = 0; i < n; i++) {
            if(!visPai[i] && vis[i] != 2) parent(i);
        }

        for(int i = 0; i < n; i++) { 
            //cout << "quantos pais eu " << i << " tenho sao -> " << pai[i] << endl;
        }

        int non = 0;
        for(int i = 0; i < n; i++)
            non += vis[i] != 2;

        //cout << "number of non cycle vertices " << non << endl;

    int goes = 0;
    root[goes] = 1;
    while(v[0] && bounded(goes + v[goes]) && root[goes+v[goes]] == -1) {
        //cout << "supostamente to aqui " << goes + v[goes] << " atualizei esse vertice ?\n";
        root[goes + v[goes]] = root[goes] + 1;
        goes += v[goes];
    }
    //cout << root[0] << ' ' << root[1] << " oioioi\n";
//    for(auto& it: root) if(~it) it++;
    int maxPath = *max_element(root.begin(), root.end());
    bool rootHasCycle = vis[0] == 2;

    vector<int> chegaEmRoot(n+1, 0);
    if(!rootHasCycle) {
        int idx = 0;
        queue<int> q; q.push(idx);
        chegaEmRoot[0] = 1;

        while(q.size()) {
            auto u = q.front(); q.pop();

            for(auto v: G[u]) if(!chegaEmRoot[v]) {
                chegaEmRoot[v] = 1;
                q.push(v);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        // if this is inside a cycle
        // ans += # of non cycle
        int cur = 0;
        if(vis[i] == 2) {

            // means this cycle comes from the
            // root, then I have to connect it to all non 
            // cycle stuff
            if(root[i] != -1) {
                ans += non;
                cur += non;
            }else {
                // means this cycle does not comes from the root
                // I will add everyone execpt
                if(!rootHasCycle) {
                    // se a raiz nao for um ciclo
                    // entao eu adiciono tudo
                    ans += n; 
                    cur += n;
                }   
                else continue;
            }
            //cout << "somando com ciclo " << cur << endl;
        } else {
            // if this doesnt lead 
            // to a cycle
            // ans += # of non cycle - # of pai 

            if(!rootHasCycle) {
                // means that
                // this is a direct path from root
                if(root[i] != -1) {
                    //cout << "oi?\n";
                    ans += non - pai[i];
                    cur += non - pai[i];
                    //cout << "vem do root\n";
                    //cout << "non = " << non << " root[i] = " << root[i] << endl;
                    //cout << "pai[0] = " << pai[0] << endl;
                }
                else {
                    // means that it doesnt have anything to 
                    // do with the root;
                    // but it is still a non cycle
                    // i just need to link to everyone
                    ans += n;
                    cur += n;
                }
            }
            else continue;
                
            //cout << "somando tirando ciclo " << cur << endl;
            //cout << "eu tenho " << pai[i] << " ancestrais" << endl;
        }
        if(i-n < 0) {
            //cout << "adicionando os vertices a esquerda " << abs(n-i) << endl;
            ans += abs(n-i);
            cur += abs(n-i);
        }
        if(i+n >= n) {
            //cout << "adicionando os vertices a direita " << abs(i+1) << endl;
            ans += abs(i+1);
            cur += abs(i+1);
        }
        //cout << "eu " << i << " tenho " << cur << " de conexoes ok\n";
    }

    cout << ans << endl;
}
}
