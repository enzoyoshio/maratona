#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  int ans = 0, rock = 0, paper = 0;

  for(auto ch: s) {
    if(ch == 'g') {
      if(paper < rock) ans++, paper++;
      else rock++;
    }else {
      if(paper < rock) paper++;
      else ans--, rock++;
    }
  }
  cout << ans << endl;
}
