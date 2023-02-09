#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> g;
vector<int> h;

void dfs(int u, int v) {
    h[u] = 0;

    for(auto w: g[u]) if(w != v) {
        dfs(w, u);
        h[u] += h[w] + 1;
    }
}
int main() {
    cin >> n;
    g.assign(n, vector<int>());
    h.assign(n, 0);

    for(int i = 1; i < n; i++) {
        int a; cin >> a;
        g[a-1].push_back(i);
    }

    dfs(0, 0);

    for(int i = 0; i < n; i++) 
        cout << h[i] << ' '; 
    cout << endl;
}
