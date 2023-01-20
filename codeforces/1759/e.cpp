#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
  int n, h;
  cin >> n >> h;
  vector<int> v(n);
  for(auto& it: v) cin >> it;
  sort(v.begin(), v.end());

  vector<int> p = {2, 2, 3};

  int ans = 0;
  
  do {
    int po = 0, cur = 0, human = h;
    for(int i = 0; i < n; i++) {
      while(po < 3 && v[i] >= human) 
        human *= p[po++];
      if(v[i] < human)
        cur++, human += v[i]/2;
    }  
    ans = max(ans, cur);
  }while(next_permutation(p.begin(), p.end()));
  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(false);

  int t=1;
  cin >> t;
  while(t--) solve();
}
