#include <bits/stdc++.h>

using namespace std;

struct dsu {
    vector<int> pai, electric, tam;
    int n;

    dsu(int n): n(n) {
        pai.assign(n, 0);
        electric.assign(n, 0);
        tam.assign(n, 1);
        iota(pai.begin(), pai.end(), 0);
    }

    int find(int x) {
        return x == pai[x] ? x : pai[x] = find(pai[x]);
    }

    bool same(int x, int u) {
        return find(x) == find(u);
    }

    bool join(int x, int u) {
        if(same(x, u)) return false;

        x = find(x);
        u = find(u);

        if(tam[x] < tam[u]) swap(x, u);

        tam[x] += tam[u];
        electric[x] += electric[u];
        pai[u] = x;
        return true;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m, e;
    cin >> n >> m >> e;
    dsu d(n+m);
    for(int i = n; i < n+m; i++)
        d.electric[i] = 1, d.tam[i] = 0;

    vector<pair<int,int>> edges(e);
    for(auto& [a, b]: edges) 
        cin >> a >> b, a--, b--;


    int q;
    cin >> q;
    vector<int> queries(q);
    vector<bool> isQ(e);
    for(int i = 0; i < q; i++)
        cin >> queries[i], queries[i]--, isQ[queries[i]] = true;

    for(int i = 0; i < e; i++) {
        if(isQ[i]) continue;

        d.join(edges[i].first, edges[i].second);
    }

    vector<int> ans(q);
    int cur = 0;

    for(int i = 0; i < n; i++) {
        if(d.electric[d.find(i)]) cur++; 
    }


    for(int i = q-1; i >= 0; i--) {
        ans[i] = cur;
        
        auto [a, b] = edges[queries[i]];

        int need = 0;
        if(!d.electric[d.find(a)]) {
            need = d.tam[d.find(a)]; 
        }
        if(!d.electric[d.find(b)]) 
            need = d.tam[d.find(b)];

        bool deu = d.join(a, b);
        if(deu && need && d.electric[d.find(a)]) 
            cur += need;
    }
    for(auto it: ans) cout << it << endl;
}
