#include <bits/stdc++.h>
using namespace std;

// Template (v1.4.2 - 2023-04-22) (codeforces:EYZ, atcoder:EYZ) {{{

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

template<class T, class U> inline void miq(T& a, U b){ if (a > b) a = b; }
template<class T, class U> inline void maq(T& a, U b){ if (a < b) a = b; }

template<class T, class U> auto &operator>>(istream &is, pair<T, U> &p) { return is >> p.ff >> p.ss; }
template<class T, class U> auto &operator<<(ostream &os, pair<T, U> const& p) { return os << '(' << p.first << ' ' << p.second << ')'; }

const auto EMPTY_STRING = "", SEPARATOR = " ";
template<class T> auto &operator>>(istream& is, vector<T> &c) { for (auto &x : c) is >> x; return is; }
template<class T> auto &operator<<(ostream& os, vector<T> const &c) { auto sep = EMPTY_STRING; for (auto x : c) os << sep << x, sep = SEPARATOR; return os; }
template<class T> auto &operator<<(ostream& os, set<T> const &c) { auto sep = EMPTY_STRING; for (auto x : c) os << sep << x, sep = SEPARATOR; return os; }
template<class T> auto &operator<<(ostream& os, multiset<T> const &c) { auto sep = EMPTY_STRING; for (auto x : c) os << sep << x, sep = SEPARATOR; return os; }
template<class T> auto &operator<<(ostream& os, unordered_set<T> const &c) { auto sep = EMPTY_STRING; for (auto x : c) os << sep << x, sep = SEPARATOR; return os; }
template<class T> auto &operator<<(ostream& os, ordered_set<T> const &c) { auto sep = EMPTY_STRING; for (auto x : c) os << sep << x, sep = SEPARATOR; return os; }
template<class T> auto &operator<<(ostream& os, deque<T> const &c) { auto sep = EMPTY_STRING; for (auto x : c) os << sep << x, sep = SEPARATOR; return os; }
template<class K, class V> auto &operator<<(ostream& os, map<K,V> const &c) { auto sep = EMPTY_STRING; for (auto x : c) os << sep << x, sep = SEPARATOR; return os; }
template<class K, class V> auto &operator<<(ostream& os, unordered_map<K,V> const &c) { auto sep = EMPTY_STRING; for (auto x : c) os << sep << x, sep = SEPARATOR; return os; }

template<class... A> void in(A &...a) { ((cin >> a), ...); }
template<class... A> void out(A const&... a) { auto sep = EMPTY_STRING; ((cout << sep << a, sep = SEPARATOR), ...); cout << '\n'; }
template<class... A> void print(A const&... a) { ((cout << a), ...); }
#define var(x) "[", #x, " ", x, "] "
template<class... A> void db(A const&... a) { ((cout << (a)), ...); cout << endl; }
//}}}

const int oo = 1e17;
int n, k, x; 
V<int> v;
V<V<int>> dp;

int f(int idx=0, int qt=k) {

  if(idx < 0) {
    return 0;
  }

  auto& ans = dp[idx][qt];

  if(~ans) return ans;

  int pega = -oo, npega = -oo;

  auto fNAOpega = f(idx-1, qt);
  auto fpega = 0;

  if(idx >= qt)
    npega = max(v[idx]-x, v[idx]-x + fNAOpega);
//  npega = max(npega, v[idx]-x + fNAOpega);

  if(qt) {
    fpega = f(idx-1, qt-1); 
    if(idx >= qt-1)
      pega = max(pega, v[idx]+x);
    pega = max(pega, v[idx]+x + fpega);
  }
  
  cerr << "\n\n------------------ db ------------------\n";
  db(var(idx), var(qt));
  db(var(pega));
  db(var(npega));
  db(var(v[idx]));
  db(var(v[idx]-x));
  db(var(v[idx]+x));
  db(var(fpega));
  db(var(fNAOpega));
  ans = max(pega, npega);
  db(var(ans));
  return ans = max(pega, npega);
}

auto main() -> signed {
  fastio;

  int t; in(t); while(t--) {
    in(n, k, x);
    v.resize(n); in(v);
    for(auto& it: v) it -= x;
    dp.assign(n, V<int>(k+1, 0));

    for(int i = 2; i<= k; i++) dp[0][i] = -oo;
    dp[0][0] = v[0];
    dp[0][1] = v[0]+x;

    for(int idx = 1; idx < n; idx++) {
      for(int qt = 0; qt <= k; qt++) {
        if(qt) {
          dp[idx][qt] = max(dp[idx][qt], v[idx]+2*x + dp[idx-1][qt-1]);
          dp[idx][qt] = max(dp[idx][qt], v[idx]+2*x);
        }
      }
      //db(var(dp[idx][k]));
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
      ans = max(ans, dp[i][k]);
    out(ans);
  }
}
