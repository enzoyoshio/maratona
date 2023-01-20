#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
  int l, r, x, a, b;
  cin >> l >> r >> x >> a >> b;

  if(a == b) {
    cout << 0 << endl;
    return;
  }  

  if(abs(a-b) >= x) {
    cout << 1 << '\n';
    return;
  }

  if(r-a >= x && r-b >= x) {
    cout << 2 << '\n';
    return;
  }

  if(a-l >= x && b-l >= x) {
    cout << 2 << '\n';
    return;
  }

  if(r-a >= x && r-l >= x && b-l >= x) {
    cout << 3 << '\n';
    return;
  }

  if(a-l >= x && r-l >= x && r-b >= x) {
    cout << 3 << '\n';
    return;
  }

  cout << -1 << '\n';

  return;

  int dif = a-b;

  // se dif < 0 -> b ta pra direita
  // se nao     -> b ta pra esquerda
  
  if(dif < 0 && a-x >= l) {
    cout << 2 << '\n';
    return;
  }
  if(dif > 0 && a+x <= r) {
    cout << 2 << '\n';
    return;
  }

  if(dif < 0 && a+x <= r && b-x >= l) {
    cout << 3 << '\n';
    return;
  }

  if(dif > 0 && a-x >= l && b+x <= r) {
    cout << 3 << '\n';
    return;
  }
  cout << -1 << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(false);

  int t=1;
  cin >> t;
  while(t--) solve();
}
