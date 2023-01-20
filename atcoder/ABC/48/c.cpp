#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  for(auto& it: v) cin >> it;
  int ans = 0;

  for(int i = 1; i < n; i++) {
  
    if(v[i] + v[i-1] <= x) continue;

    int dif = v[i] + v[i-1] -x;
    ans += dif;
    v[i] -= dif;
    v[i] = max(v[i], 0LL);
  }


  cout << ans;
}
