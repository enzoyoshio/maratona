#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
  cin.tie(0)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;

  vector<int> v(n);
  for(auto& it: v) cin >> it;
  sort(v.rbegin(), v.rend());
  for(int i = 1; i < n; i++) v[i] += v[i-1];

  while(q--) {
    int x, y;
    cin >> x >> y;
    x--;
    cout << v[x] - (x-y >= 0 ? v[x-y] : 0) << '\n';
  }
}
