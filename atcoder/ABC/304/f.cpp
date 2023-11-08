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

const int MOD = 998244353;
int add(int a, int b) { return (a+b)%MOD;}
int sub(int a, int b) { return ((a-b)%MOD + MOD)%MOD;}
int mul(int a, int b) { return (a*b)%MOD;}
int fexp(int b, int e=MOD-2) {
  if(e == 0) return 1LL;

  int x = fexp(b, e/2);
  x = mul(x, x);
  if(e%2) x = mul(x, b);
  return x;
}

auto main() -> signed {
  fastio;

  int n; string s;
  in(n, s);
  V<int> ans(n);
  ans[1] = 1;

  set<int> need;
  for(int i = 0; i < n; i++) {
    if(s[i] == '.') need.insert(i+1);
  }

  if(need.empty()) ans[1]++;

  for(int i = 2; i*i <= n; i++) {
    if(n%i == 0) {
      set<int> mods;
      for(auto it: need)
        mods.insert(it%i);
      ans[i] = fexp(2, i-(int)mods.size());
      if(i*i != n) {
        int ni = n/i;
        mods.clear();
        for(auto it: need)
          mods.insert(it%ni);
        ans[ni] = fexp(2, ni - (int)mods.size());
      }
    }
  }

  /*
  for(int i = 0; i < n; i++) {
    db(var(i), var(ans[i]));
  }
  */

  for(int i = 1; i < n; i++) {
    for(int j = i+i; j < n; j+=i) {
      ans[j] = sub(ans[j], ans[i]);
    }
  }

  /*
  for(int i = 0; i < n; i++) {
    db(var(i), var(ans[i]));
  }
  */

  int res = ans[1];
  for(int i = 2; i*i <= n; i++) {
    if(n%i == 0) {
      res = add(res, ans[i]);
      if(i*i != n)
        res = add(res, ans[n/i]);
    }
  }

  cout << res << endl;
}
