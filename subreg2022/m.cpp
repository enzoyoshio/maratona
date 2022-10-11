#include <bits/stdc++.h>
using namespace std;

#define cond(c, x, y) ((c) ? (x) : (y))
#define all(v) (v).begin(), (v).end()
#define int long long
using ii = pair<int, int>;

const int MAXN = 1e5 + 8;
const int INF = 0x3f3f3f3f3f3f3f3fLL;
vector<int> factors[MAXN];

int position[MAXN];
vector<ii> delta[MAXN];

// when in [1, q]
int getValWhen(int i, int when) {
  int pos = position[i];
  int idx = i+1; 
  for (int bitmask = 1; bitmask != (1 << factors[idx].size()); bitmask++) {
    int num = 1;
    for (int j = 0; j < factors[idx].size(); j++)
      if (bitmask&(1 << j))
        num *= factors[idx][j];
    auto ub = upper_bound(all(delta[num]), ii{when+1, -INF});
    if (ub == delta[num].begin()) continue;
    else ub--;
    auto [curwhen, curlast] = *ub;
    pos -= curlast;
  }
  return pos;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int p = 2; p < MAXN; p++) {
    if (factors[p].empty()) {
      for (int j = p; j < MAXN; j += p) {
        factors[j].push_back(p);
      }
    }
  }

  for (int i = 0; i < MAXN; i++) {
    delta[i].push_back(ii{0, 0});
  }

  int n, q; cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> position[i]; 
  for (int i = 0; i < q; i++) {
    int c, d; cin >> c >> d;
    for (int bitmask = 1; bitmask != (1 << factors[c].size()); bitmask++) {
      int num = 1;
      for (int j = 0; j < factors[c].size(); j++)
        if (bitmask&(1 << j))
          num *= factors[c][j];
      auto [lastwhen, lastval] = delta[num].back();
      delta[num].push_back({i+1, lastval + cond(__builtin_popcountll(bitmask)%2, 1, -1) * d});
    }
  }

  for (int i = 0; i < n; i++) {
    int m = 1, M = q;
    int best = -1;
    while (m <= M) {
      int mid = (m+M)/2;      
      if (getValWhen(i, mid) <= 0) best = mid, M = mid-1;
      else m = mid+1;
    }
    cout << best << endl;
  }
}
