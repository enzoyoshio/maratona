#include <bits/stdc++.h>

using namespace std;

#define int long long


int m, c;
vector<int> v(100);

void solve() {
  for(auto& it: v) it=1;
  cin >> m >> c;

  int mas = 0;
  for(int i = 0; i < m; i++) {
    int a; cin >> a;
    v[a] = 0;
    mas = max(mas, a);
  }

  int idx=1, ans = 0;

  while(idx < 100 && ans < c) {
    mas = max(mas, idx);
    if(!v[idx]) idx++;
    else {
      ans += idx;
      v[idx++] = 0;
    }

  }

  for(int i = 1; i <= mas; i++) {
    if(v[i]) {
      cout << "NO\n";
      return;
    }
  }

  cout << (ans == c ? "yes" : "no") << endl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(false);

  int t=1;
  cin >> t;
  while(t--) solve();
}
