#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9+7;

int add(int a, int b) { return ((a+b)%MOD +MOD)%MOD;}
int mul(int a, int b) { return ((a*b)%MOD +MOD)%MOD;}
int absmod(int a) {return ((a%MOD)+MOD)%MOD;}

signed main() {
  cin.tie(0)->sync_with_stdio(false);
  
  int n, k;
  cin >> n >> k;
  vector<int> v(n), neg, nonneg;
  for(auto& it: v) {
    cin >> it;
    if(it < 0) neg.push_back(it);
    else nonneg.push_back(it);
  }
  sort(rbegin(v), rend(v));
  
  // se for so positivo
  if(v.back() >= 0) {
    int ans = 1;
    for(int i = 0; i < k; i++) ans = mul(ans, v[i]);
    return cout << absmod(ans) << endl, 0;
  }
  
  // se so tiver negativo
  if(v[0] < 0) {
    int ans = 1;

    if(k%2 == 0)
      reverse(begin(v), end(v));

    for(int i = 0; i < k; i++)
      ans = mul(ans, v[i]);
    
    cout << absmod(ans) << endl;
    return 0;
  }
  
  int l = 0, r = n-1;
  int ans = 1;

  for(int i = 0; i < k; i++) {
    ans = mul(ans, v[i]);
  }
  
  while(k > 1) {
    int val = 1;
    if(val * v[l] * v[l+1] > val * v[r] * v[r-1]) {
      ans = mul(ans, v[l]);
      ans = mul(ans, v[l+1]);
      l += 2;
    }else {
      ans = mul(ans, v[r]);
      ans = mul(ans, v[r-1]);
      
      r -= 2;
    }
    k -= 2;
  }
  
  if(k == 1)
    ans = mul(ans, max(v[l], v[r]));
  
  cout << absmod(ans) << endl;
}
