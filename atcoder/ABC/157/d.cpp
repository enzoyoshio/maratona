#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+7;
vector<int> pai(MAXN), tam(MAXN, 1);
vector<int> amigo[MAXN], enemy(MAXN, 0);;

int find(int u) { return u == pai[u] ? u : pai[u] = find(pai[u]);}

void join(int u, int v) {
    u = find(u);
    v = find(v);

    if(u == v) return;

    if(tam[u] < tam[v]) swap(u, v);

    pai[v] = u;
    tam[u] += tam[v];
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    iota(pai.begin(), pai.end(), 0LL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int>> friendship(m), blockship(k);
    for(auto& [a, b]: friendship) {
        cin >> a >> b;
        
        join(a, b);
        amigo[a].push_back(b);
        amigo[b].push_back(a);
    }
    for(auto& [a, b]: blockship) {
        cin >> a >> b;
        if(find(a) == find(b)) {
            enemy[a]++;
            enemy[b]++;
        }
    }
    
    vector<int> ans(n+1, 0);

    for(int i = 1; i <= n; i++) {
        ans[i] = tam[find(i)] - enemy[i] - amigo[i].size() -1;
    }

    for(int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;
}
