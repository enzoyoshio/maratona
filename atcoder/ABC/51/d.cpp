#include <bits/stdc++.h>

#define int long long

using namespace std;

bool check(vector<vector<int>> v,
                          vector<vector<int>> checker) {
  int n = v.size();
  for(int k = 0; k < n; k++) 
    for(int i = 0; i < n; i++) 
      for(int j = 0; j < n; j++) 
        v[i][j] = min(v[i][j], v[i][k] + v[k][j]);

  cout << "testando\n";
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) 
      cout << v[i][j] << ' '; cout << endl;
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(v[i][j] > checker[i][j]) return true;
    }
  }
  
  return false;

}

const int oo = 1e8;

signed main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(n, oo));
  vector<tuple<int,int,int>> edges(m);

  for(int i = 0; i < m; i++) {
    auto& [a, b, c] = edges[i];
    cin >> a >> b >> c;
    a--, b--;
    v[a][b] = c;
    v[b][a] = c;
  }

  auto teste = v;

  cout << "before djikstra\n";
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      cout << v[i][j] << ' '; cout << endl;
  }

  for(int k = 0; k < n; k++) 
    for(int i = 0; i < n; i++) 
      for(int j = 0; j < n; j++) 
        v[i][j] = min(v[i][j], v[i][k] + v[k][j]);

  cout << "best way\n";
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      cout << v[i][j] << ' '; cout << endl;
  }
  int ans = 0;
  for(int i = 0; i < m; i++) {
    auto [a, b, c] = edges[i];

    teste[a][b] = oo;
    teste[b][a] = oo;

    if(check(teste, v)) ans++; 

    teste[a][b] = c;
    teste[b][a] = c;
  }

  cout << n - ans << endl;
}
