#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
  int n, m; 
  cin >> n >> m;

  int qt2 = 0, aux1 = n, aux2 = n, qt5 = 0;
  while(aux1%2 == 0) {
    qt2++;
    aux1 /= 2;
  }  

  while(aux2%5 == 0) {
    qt5++;
    aux2 /= 5;
  }

  int qt0 = min(qt2, qt5);
  qt2 -= qt0, qt5 -= qt0;

  int num = 1, i;
  for(i = qt0+1; i < 18; i++) {
    if(qt5 && 2*num < m) 
        num *= 2, qt5--;
    else if(qt2 && 5*num < m)
        num *= 5, qt2--;
    else if(10*num < m) 
        num *= 10;
  }

  if(num == 1) 
    cout << n*m << '\n';
  else 
    cout << n * (m/num * num) << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(false);

  int t=1;
  cin >> t;
  while(t--) solve();
}
