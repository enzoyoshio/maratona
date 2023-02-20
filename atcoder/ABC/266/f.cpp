#include <bits/stdc++.h>

using namespace std;

#define db(x) cout << "[ " << #x << " = " << x << " ]\n"

const int MAXL = 20;
const int MAXN =3e5;
int n;
int timer = 0;
// tree and compressed
vector<vector<int>> g, compressed;
vector<int> visited;
// euler tour
vector<int> in(MAXN), out(MAXN);
// problem especification
vector<int> value(MAXN, 0);
// lca
vector<vector<int>> up(MAXN, vector<int>(MAXL, 0));
vector<vector<int>> max_val(MAXN, vector<int>(MAXL, 0));
// dfs on tree
vector<int> dp(MAXN, 0);

struct DSU {
    vector<int> pai, tam;
    int n;

    DSU(int n): n(n) {
        pai.assign(n, 0);
        iota(pai.begin(), pai.end(), 0);
        tam.assign(n, 1);
    }

    int find(int u) { return u == pai[u] ? u : pai[u] = find(pai[u]);}

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    void join(int u, int v) {
        if(same(u, v)) return;
        u = find(u);
        v = find(v);

        if(tam[u] < tam[v]) swap(u, v);

        tam[u] += tam[v];
        pai[v] = u;
    }
};

DSU d(MAXN);

void dfs(int u, int v) {

//    cout << "cheguei no " << u << " meu pai eh "<< v << endl;
    
    visited[u] = 2;

    for(auto el: g[u]) if(el != v) {

        // se eu ja visitei ele
        // eh um backedge
        if(visited[el] == 2) {

     //       cout << "Meu pai eh " << v << endl;
            // eh meu ancestral 
      //      cout << "to incrementando " << u << endl;
       //     cout << "to decrementando " << el << endl;
            dp[el]--;
            dp[u]++;
        }else if(!visited[el]) {
            // se nao eh um edge normal
    //        cout << "indo pro meu filho " << el << " eu sou " << u << endl;
            dfs(el, u);    
            dp[u] += dp[el];
        }
    }

    visited[u] = 1;
    if(dp[u]) {
        d.join(d.find(u), d.find(v));
        cout << "que caralhas eu to mergeando\n";
        db(u);
        db(v);
    }
//    cout << "saindo de " << u << " meu pai eh " << v << endl;
//    cout << "I am " << u << " my dp is " << dp[u] << endl;
//    for(int i = 0; i < 10; i++) {
//        cout  << "currently dp[" << i << "] = " << dp[i] << endl;
//    }
}

void euler(int u, int v) {
    in[u] = ++timer;
    up[u][0] = v;
    max_val[u][0] = value[u];
    for(int i = 1; i < MAXL; i++) {
        up[u][i] = up[up[u][i-1]][i-1];
        max_val[u][i] = max(max_val[u][i-1], max_val[up[u][i-1]][i-1]);
    } 

    for(auto el: compressed[u]) if(el != v) {
        euler(el, u);
    }

    out[u] = ++timer;
}

bool is_ancestor(int u, int v) {
    return in[u] <= in[v] && out[v] <= out[u];
}

int lca(int u, int v) {
    
    if(is_ancestor(u, v)) {
        int res = 0;
        for(int i = MAXL-1; i >= 0; i--) {
            if(!is_ancestor(up[v][i], u)) {
                res = max(res, max_val[v][i]);
                v = up[v][i];
            }
        }
        return res;
    }
 
    if(is_ancestor(v, u)) {
        int res = 0;
        for(int i = MAXL-1; i >= 0; i--) {
            if(!is_ancestor(up[u][i], v)) {
                res = max(res, max_val[u][i]);
                u = up[u][i];
            }
        }
        return res;
    }

    int saveu = u, savev = v;
    int ans = 0;
    
    for(int i = MAXL-1; i >= 0; i--) {
        if(!is_ancestor(up[saveu][i], v)) {
            ans = max(ans, max_val[saveu][i]);
            saveu = up[saveu][i];
        }
        if(!is_ancestor(up[savev][i], u)) {
            ans = max(ans, max_val[savev][i]);
            savev = up[savev][i];
        }
    }

    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    set<pair<int,int>> neighbour;
    g.assign(n, vector<int>());
    compressed.assign(n, vector<int>());
    visited.assign(n, 0);

    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
        neighbour.emplace(a, b);
        neighbour.emplace(b, a);
    }

    // merge cycles 
    // lca

    dfs(0, 0);
    for(auto [a, b]: neighbour) {
        if(!d.same(a, b)) 
            compressed[d.find(a)].push_back(d.find(b));
    }
    for(int i = 0; i < n; i++) {
        if(i == d.find(i) && d.tam[i] > 1)
            value[i] = 1;
    }
    for(int i = 0; i < n; i++)
        db(dp[i]), db(i);

    for(int i = 0; i < n; i++) {
        cout << "i am " << i << endl;
        cout << "My parent is " << d.find(i) << endl;
    }

    for(int i = 0; i < n; i++) {
        if(compressed[i].size()) {
            cout << "No = " << i << endl;
            for(auto e: compressed[i])
                cout << e << ' ';
            cout << endl;
        }
    }
    euler(d.find(0), d.find(0));

    int q;
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(neighbour.find(make_pair(a, b)) != neighbour.end() && !d.same(a, b)) {
            cout << "Yes" << endl;
            continue;
        }

        if(d.same(a, b) || (d.find(a) != a && d.find(b) != b)) {
            cout << "No" << endl;
            continue;
        }

        if(lca(a, b))   cout << "No\n";
        else            cout << "Yes\n"; 
    }
}
