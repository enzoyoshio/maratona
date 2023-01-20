#include <bits/stdc++.h>

using namespace std;

char q1(int i) {
  cout << "? " << 1 << ' ' << i << '\n';
  fflush(stdout);

  char c; cin >> c;
  return c;
}

int q2(int l, int r) {
  cout << "? " << 2 << ' ' << l << ' ' << r << '\n';
  fflush(stdout);

  int n; cin >> n;
  return n;
}

int main() {
  //cin.tie(0)->sync_with_stdio(false);

  int n; cin >> n;
  string s;
  //bitset<32> tam(n);
  for(int i = 0; i < n; i++) s.push_back('0');

  for(int i = 0; i < n; i++) {
    
    int l = i, r = n-1;

    s[i] = q1(i+1);
    char an = s[i];
    int j = i;
    while(l <= r) {
      int mid = (l+r)/2;
      int qt = q2(i+1, mid+1);

      if(qt > 1) {
        r = mid-1;
      }else {
        l = mid+1, j = mid;
      }
    }

    while(i <= j) s[i] = an, i++;
    i--;
  }

  cout << "! " << s << '\n';
}
