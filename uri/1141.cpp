#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n;
  while(cin >> n && n > 0) {
    vector<string> v(n);
    vector<int> ans(n, 1);
    for(auto& it: v) cin >> it;
    sort(v.begin(), v.end());
  
    for(auto it: v) cout << it << '\n';
    for(int i = 0; i < n; i++) {
      for(int j = i+1; j < n; j++) {
        if(v[j].find(v[i]) != string::npos) ans[j] = max(ans[j], ans[i]+1);
      }
    }

    cout << *max_element(ans.begin(), ans.end()) << '\n';
  }
}
