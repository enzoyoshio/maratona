#include <bits/stdc++.h>
using namespace std;

// Template (v1.4.2 - 2023-04-22) (codeforces:cebolinha, atcoder:edu) {{{

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#define int long long
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

template<class T> using V = vector<T>;
template<class T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
using ii = pair<int, int>;
using iii = array<int, 3>;

#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define sz(x) (int) (x).size()
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define nemo ><>
#define loop(ii, n) for (int ii = 0; ii < (n); ii++)
#define cond(c, t, f) ((c) ? (t) : (f))
#define mem(a, b) memset((a), (b), sizeof(a))
#define inbounds(x, l, r) ((l) <= (x) && (x) <= (r))
#define L1(res...) [&](auto x){ return res; }
#define L2(res...) [&](auto x, auto y){ return res; }

//}}}

signed main() {
  fastio;

  int t; cin >> t; while(t--) {
    int n, m;
    cin >> n >> m;
    V<int> v(m);
    for(auto& it: v)
      cin >> it;
    sort(begin(v), end(v));

    priority_queue<int> dif;
    for(int i = 0; i+1 < m; i++) {
      dif.push(abs(v[i]-v[(i+1)%m]) - 1);
    //  cout << abs(v[i] - v[(i+1)%m]) - 1 << ' ';
    }
    dif.push(v[0] + n - v.back() - 1);
    //cout << v[0] + n - v.back() - 1 << endl;

    int timer = 0;
    int ans = 0;

    while(dif.size() && dif.top() - 2*timer -1 > 0) {
      if(dif.top() == 1)  ans++;
      else                ans += dif.top() - (2*timer+1);
     // cout << "timer = " << timer << endl;
      //cout << "dif.top() = " << dif.top() << endl;
      //cout << "dif.top() - 2*timer = " << dif.top()  - 2*timer << endl;
      timer += 2;
      dif.pop();
    }
    if(dif.size() && dif.top() - 2*timer > 0) ans++;

    cout << n-ans << endl;
    
  }
}


