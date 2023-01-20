#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n; 
  string s, t;
  cin >> n >> s >> t;

  for(int i = 0; i < n; i++) {
    if(s[i] == t[i]) {
      continue;
    }  

    if(abs(s[i]-t[i]) == 2) {
      cout << "no\n";
      return;
    }

    if(s[i] == t[i] + 1) {
      cout << "no\n";
      return;
    }

    int j = i;
    while(j < n && s[j] == s[i]) j++;

    if(j == n || s[j] != t[i]) {
      cout << "no\n";
      return;
    }

    swap(s[i], s[j]);
  }

  cout << "yes\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int q; cin >> q; while(q--) solve();
}
