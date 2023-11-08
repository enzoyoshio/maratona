#include <bits/stdc++.h>

using namespace std;

// O(e)
int expp(int b, int e) {

  if(e == 0) return 1;

  return b * expp(b, e-1);
}

// O(log(e))
int fexp(int b, long long e) {
  if(e == 0) return 1;
  int x = fexp(b, e/2);
  x *= x;
  if(e%2) x *= b;
  return x;
}

int main() {
  long long b, e;
  cin >> b >> e;
  cout << fexp(b, e) << endl;
  /*
  int ans = 1;
  for(int i = 1; i <= e; i++)
    ans *= b;
  cout << ans << endl;
  */
//  cout << expp(b, e) << endl;
}
