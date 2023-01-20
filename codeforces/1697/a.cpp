#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int t; cin >> t; while(t--) {
    int n, m; cin >> n >> m;
    vector<int> v(n);
    for(auto& it: v) cin >> it;
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << max(0, sum-m) << '\n';
  }
}
