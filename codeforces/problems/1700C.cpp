#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n), d(n), suf(n), pref(n);
  for(auto& it: v) cin >> it;


  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int t; cin >> t;
  while(t--) solve();

}
