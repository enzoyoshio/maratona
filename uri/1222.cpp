#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n, l, c;

  while(cin >> n >> l >> c) {
    vector<string> v(n);
    for(auto& it: v) cin >> it;

    vector<string> linhas;
    linhas.push_back("");
    for(auto it: v) {
      if(linhas.back().size() + it.size() <= c) linhas.back() += it + " ";
      else linhas.push_back(it + " "); 
    }

    cout << (linhas.size() + l-1)/l << '\n';
  }
}
