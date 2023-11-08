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

using iiii = array<int,4>;
const int oo = 1e17;

auto main() -> signed {
  fastio;

  int n, m;
  in(n, m);

  V<ii> temp(n);
  for(int i = 0; i < n; i++) {
    cin >> temp[i].first;
    temp[i].second = i;
  }

  sort(all(temp));
  V<int> rev(n);
  for(int i = 0; i < n; i++)
    rev[temp[i].second] = i;

  vector dist(n, vector<int>(n, oo));
  for(int i = 0; i < n; i++)
    dist[i][i] = 0;

  for(int i = 0; i < m; i++) {
    int a, b, c; cin >> a >> b >> c; a--, b--;
    a = rev[a]; b = rev[b];
    dist[a][b] = c;
    dist[b][a] = c;
  }

  auto cpy = dist;

  int q;
  in(q);
  V<int> ans(q, -1);
  V<V<iii>> coldest(n+3, vector<iii>()), hottest(n+3, vector<iii>());
  for(int i = 0; i < q; i++) {
    int a, b, k, t;
    in(a, b, k, t);
    a--, b--;
    a = rev[a]; b = rev[b];
    if(t == 0) {
      coldest[k].push_back({a, b, i});
    }else {
      hottest[k].push_back({a, b, i});
    }
  }

  set<int> qt;
  for(int k = 0; k < n; k++) {

    if(qt.find(temp[k].first) == qt.end()) {
      int id = qt.size();

      for(auto [a, b, idx]: coldest[id]) {
        if(dist[a][b] != oo) ans[idx] = dist[a][b];
      } 
    }
    qt.insert(temp[k].first);

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  for(int id = qt.size(); id <= n; id++) {
    for(auto [a, b, idx]: coldest[id]) {
      if(dist[a][b] != oo) ans[idx] = dist[a][b];
    } 
  }

  dist = cpy;
  qt.clear();
  for(int k = n-1; k >= 0; k--) {

    if(qt.find(temp[k].first) == qt.end()) {
      int id = qt.size();

      for(auto [a, b, idx]: hottest[id]) {
        if(dist[a][b] != oo) ans[idx] = dist[a][b];
      } 
    }
    qt.insert(temp[k].first);

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  for(int id = qt.size(); id <= n; id++) {
    for(auto [a, b, idx]: hottest[id]) {
      if(dist[a][b] != oo) ans[idx] = dist[a][b];
    } 
  }
  for(auto it: ans) cout << it << '\n';
}
