#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(false);

  int n, t;
  cin >> n >> t;
  vector<int> v(n);
  vector<int> pmin(n);
  for(auto& it: v) 
    cin >> it;

  pmin[0] = v[0];
  for(int i = 1; i < n; i++) {
    pmin[i] = min(v[i], pmin[i-1]);
  }

  map<int,int> f;
  for(int i = 1; i < n; i++) {
    if(pmin[i-1] < v[i])
     f[v[i]-pmin[i-1]]++; 
  }

  cout << f.rbegin()->second << endl;

}
