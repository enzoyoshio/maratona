#include <bits/stdc++.h>

using namespace std;

#define int long long

int sz[55];
int patties[55];

int ans(int n, int x) {

  if(x <= 0) return 0;
  if(n == 0) {
    return 1;
  }

  int res = 0;

  // se eu tenho q comer mais ou igual q a metade do sanduiche
  // eu subtraio a qt de comida de da metade que vai ser sz[n-1] menos o bun e o pattie
  // e depois eu calculo quanto que eu ganho pra outra metade
  if(x >= sz[n-1]+2) {
    x -= sz[n-1]+2;
    res += patties[n-1] + 1;
    res += ans(n-1, x);
  }else {
    res = ans(n-1, x-1);
  }

  return res;
}

signed main() {
  cin.tie(0)->sync_with_stdio(false);

  sz[0] = 1;
  patties[0] = 1;

  for(int i = 1; i < 55; i++) {
    sz[i] = 2*sz[i-1] + 3;
    patties[i] = 2*patties[i-1] + 1;
  }

  int n, x; cin >> n >> x;
  cout << ans(n, x) << '\n';
}
