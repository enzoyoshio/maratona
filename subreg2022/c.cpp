#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3 + 8;

bool been[MAXN][MAXN];
bool walls[MAXN][MAXN];

const int di[] = {-2, 2, 0, 0};
const int dj[] = {0, 0, -2, 2};
int bfs(int x, int y) {
  been[x][y] = true;
  queue<pair<int, int>> Q; Q.push({x, y});
  int visited = 0;
  while (!Q.empty()) {
    visited++;
    auto [i, j] = Q.front(); Q.pop();
    for (int k = 0; k < 4; k++) {
      int ni = i + di[k], nj = j + dj[k];
      int wi = i + di[k]/2, wj = j + dj[k]/2;
      if (0 < ni && ni < MAXN) {
        if (0 < nj && nj < MAXN) {
          if (!been[ni][nj] && !walls[wi][wj]) {
            been[ni][nj] = true;        
            Q.push({ni, nj});
          }
        }
      }
    }
  }
  return visited;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  int x0, y0; cin >> x0 >> y0; x0 *= 2, y0 *= 2;

  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y; x *= 2, y *= 2;
    for (int i = min(x0, x); i <= max(x0, x); i++) {
      for (int j = min(y0, y); j <= max(y0, y); j++) {
        walls[i][j] = true;
      }
    }
    x0 = x, y0 = y;
  }

  bfs(1, 1);

  int best = 0;
  for (int i = 3; i < MAXN; i+=2) {
    for (int j = 3; j < MAXN; j+=2) {
      if (!been[i][j]) {
        best = max(best, bfs(i, j));
      }
    }
  }
  cout << best << endl;
}
