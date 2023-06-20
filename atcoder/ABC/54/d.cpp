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

const int oo = 1e15;

map<ii, int> faz(V<iii> &v) {

  map<ii, int> c;
  int n = sz(v);

  for(int bitmask = 1; bitmask < 1 << n; bitmask++) {
    iii cur = {0, 0, 0};
    for(int i = 0; i < n; i++) {
      if((bitmask >> i) & 1) {
        cur[0] += v[i][0];
        cur[1] += v[i][1];
        cur[2] += v[i][2];
      }
    }

    if(c.find({cur[0], cur[1]}) == c.end()) c[{cur[0], cur[1]}] = cur[2];
    else miq(c[{cur[0], cur[1]}], cur[2]);
  }
  return c;
}

auto main() -> signed {
  fastio;

  int n, ma, mb;
  in(n, ma, mb);

  V<iii> v(n);
  for(int i = 0; i < n; i++)
    cin >> v[i][0] >> v[i][1] >> v[i][2];

  V<iii> v1, v2;
  for(int i = 0; i < n/2; i++) {
    v1.eb(v.back());
    v.pop_back();
  }
  while(v.size()) {
    v2.eb(v.back());
    v.pop_back();
  }

  auto first = faz(v1), second = faz(v2);

  int ans = oo;
  first[{0, 0}] = 0;
  for(auto [a, b]: first) {
    auto [num, den] = a;

    for(int i = 0; i < 50; i++) {
      int need_num = ma*i - num;
      int need_den = mb*i - den;
      if(need_num < 0 || need_den < 0) continue;

      if(second.find({need_num, need_den}) != second.end()) {
        ans = min(ans, b + second[{need_num, need_den}]);
      }
      if(!need_num && !need_den && num && den) {
        ans = min(ans, b);
      }
    }
  }

  if(ans == oo) out(-1);
  else out(ans);
}
