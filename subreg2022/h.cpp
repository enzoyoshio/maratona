#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 8;

int n, m;

vector<int> G[MAXN], Ginv[MAXN];
int compAmount = 0;
int comp[MAXN];
bool vis[MAXN];
stack<int> S;

void dfs(int v) {
  vis[v] = true;
  for (auto u : G[v]) if (!vis[u]) dfs(u);
  S.push(v); 
}

void scc(int v, int c) {
  vis[v] = true, comp[v] = c;
  for (auto u : Ginv[v]) if (!vis[u]) scc(u, c);
}

void korajasu() {
  for (int i = 0; i < n; i++) vis[i] = false;
  for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);
  for (int i = 0; i < n; i++) vis[i] = false;
  while (!S.empty()) {
    int v = S.top(); S.pop();
    if (!vis[v]) scc(v, compAmount++);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int v, u; cin >> v >> u; v--, u--;
    G[v].push_back(u);
    Ginv[u].push_back(v);
  }

  korajasu();

  vector<int> compDin(compAmount), compDout(compAmount);
  for (int v = 0; v < n; v++) {
    for (auto u : G[v]) {
      if (comp[v] != comp[u]) {
        compDout[comp[v]]++;
        compDin[comp[u]]++;
      }
    }
  }  

  int sources = 0, sinks = 0;
  for (int i = 0; i < compAmount; i++) {
    sources += (compDin[i] == 0);
    sinks += (compDout[i] == 0);
  }

  if (compAmount == 1) {
    cout << 0 << endl;
  } else {
    cout << max(sources, sinks) << endl;
  }
}
