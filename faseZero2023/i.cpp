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

const int oo = 1e18;
const int MAXN = (1 << 10);
V<int> tb(MAXN, -1), proximo(MAXN, -1);
V<int> vis(MAXN, 0);

int toggle(int bit, int i) {
    int newbit = bit;
    if(i == 0) {
      newbit ^= (1 << 1);
      newbit ^= (1 << 4);
    }else if(i == 1) {
      newbit ^= (1 << 0);
      newbit ^= (1 << 2);
      newbit ^= (1 << 4);
      newbit ^= (1 << 5);
    }else if(i == 2) {
      newbit ^= (1 << 1);
      newbit ^= (1 << 3);
      newbit ^= (1 << 5);
      newbit ^= (1 << 6);
    }else if(i == 3) {
      newbit ^= (1 << 2);
      newbit ^= (1 << 6);
    }else if(i == 4) {
      newbit ^= (1 << 0);
      newbit ^= (1 << 1);
      newbit ^= (1 << 5);
      newbit ^= (1 << 7);
    }else if(i == 5) {
      newbit ^= (1 << 1);
      newbit ^= (1 << 2);
      newbit ^= (1 << 4);
      newbit ^= (1 << 6);
      newbit ^= (1 << 7);
      newbit ^= (1 << 8);
    }else if(i == 6) {
      newbit ^= (1 << 2);
      newbit ^= (1 << 3);
      newbit ^= (1 << 5);
      newbit ^= (1 << 8);
    }else if(i == 7) {
      newbit ^= (1 << 4);
      newbit ^= (1 << 5);
      newbit ^= (1 << 8);
      newbit ^= (1 << 9);
    }else if(i == 8) {
      newbit ^= (1 << 5);
      newbit ^= (1 << 6);
      newbit ^= (1 << 7);
      newbit ^= (1 << 9);
    }else if(i == 9) {
      newbit ^= (1 << 7);
      newbit ^= (1 << 8);
    }
    return newbit;
}

int dp(int bit) {
  if(__builtin_popcountll(bit) == 10) return 0;

  if(vis[bit] == 1) return tb[bit];
  if(vis[bit] == 2) return oo;

  vis[bit] = 2;
  auto& ans = tb[bit];
  if(~ans) return ans;
  ans = oo;

  for(int i = 0; i < 10; i++) {
    int newbit = toggle(bit, i);
    int cur = 1 + dp(newbit);
    if(cur < ans) {
      ans = cur;
      proximo[bit] = i;
    }
  }

  vis[bit] = 1;
  return ans;
}

auto main() -> signed {
  fastio;

  int x = 0;
  for(int i = 0; i < 10; i++) {
    int a; cin >> a;
    x |= a << i;
  } 

  auto ans = dp(x);
  if(ans == oo) out(-1);
  else {
    out(ans);
    while(__builtin_popcountll(x) < 10) {
      cout << proximo[x]+1;
      x = toggle(x, proximo[x]);
      if(__builtin_popcountll(x) == 10) cout << '\n';
      else cout << ' ';
    }
  }
}
