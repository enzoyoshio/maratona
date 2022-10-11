#include <bits/stdc++.h>

using namespace std;

int valor(int n) {
  return min(n, 10);
}

int main() {
  vector<int> f(20, 4);
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  f[a]--, f[b]--, f[c]--, f[d]--;

  vector<int> v(n);
  int carta = 0;
  for(auto& it: v) cin >> it, f[it]--, carta += valor(it);

  int maria = valor(c) + valor(d) + carta;
  int joao = valor(a) + valor(b) + carta;

  for(int i = 1; i <= 13; i++) {
    if(f[i] == 0) continue;

    if((joao + valor(i) > 23 and maria+valor(i) <= 23) 
        or 
        (maria + valor(i) == 23) ) 
        return cout << i << endl, 0;
  }

  cout << -1;
}
