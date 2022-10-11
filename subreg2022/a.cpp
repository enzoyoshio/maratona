#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  string s; cin >> s;
  int a = 0;
  int ans = 0;
  for (auto c : s) { 
    if (c == 'a') a++;
    else {
      if (a >= 2) ans += a;
      a = 0;
    }
  }
  if (a >= 2) ans += a;
  
  cout << ans << endl;
}
