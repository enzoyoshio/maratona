#include <bits/stdc++.h>

using namespace std;

#define int long long

struct DSU {
    vector<int> pai, tam;
    int n;

    DSU(int n): n(n) {
        pai.assign(n, 0);
        tam.assign(n, 1);

        iota(pai.begin(), pai.end(), 0LL);
    }

    int find(int x) { return x == pai[x] ? x : pai[x] = find(pai[x]);}

    int size(int x) {
        return tam[find(x)];
    }

    int same(int a, int b) {
        return find(a) == find(b);
    }

    void join(int a, int b) {
        a = find(a);
        b = find(b);

        if(a == b) return;

        if(tam[a] < tam[b]) swap(a, b);

        tam[a] += tam[b];
        pai[b] = pai[a];
    }
};

int sum(int n) {
    return n*(n-1)/2;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    DSU d(n);
    vector<pair<int,int>> edges(m);
    vector<int> ans(m);
    for(auto& [a, b]: edges)
        cin >> a >> b, a--, b--;

    int acum = sum(n);

    for(int i = m-1; i >= 0; i--) {
        ans[i] = acum;

        auto [x, y] = edges[i];

        if(d.same(x, y)) continue;

        acum += sum(d.size(x));
        acum += sum(d.size(y));
        d.join(x, y);
        acum -= sum(d.size(x));
    }

    for(auto it: ans) cout << it << endl;
}
