#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
  int n, p, mini = 1e9, maxi = -1;
  cin >> n >> p;
  vector<int> v(n);
  for(auto& it: v) cin >> it, mini = min(mini, it), maxi = max(maxi, it);

  int num = v.back();

    
}

signed main() {
  cin.tie(0)->sync_with_stdio(false);

  int t=1;
  cin >> t;
  while(t--) solve();
}
