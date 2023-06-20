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

auto main() -> signed {
  fastio;

  int h, w, n;
  in(h, w, n);

  ii start, finish;
  in(start, finish);

  set<ii> pontos;
  map<int, set<int>> xs, ys;
  for(int i = 0; i < n; i++) {
    int a, b; in(a, b);
    pontos.emplace(a, b);
    xs[a].insert(b);
    ys[b].insert(a);
  }

  V<ii> lado = {
    {-1, 0},
    {1, 0},
    {0, 1},
    {0, -1},
  };
  queue<ii> q;
  q.emplace(start);
  map<ii, int> dist;
  dist[start] = 0;
  while(q.size()) {
    auto [x, y] = q.front(); q.pop();

    if(ii{x, y} == finish) return out(dist[{x, y}]), 0;

    auto posx = xs[x].upper_bound(y);
    // se tiver algum y nessa reta, pegar o primeiro
    if(posx != xs[x].end() && 
       *posx-1 > y && 
       dist.find({x, *posx-1}) == dist.end()) {
        q.emplace(x, *posx-1);
        dist[{x, *posx-1}] = dist[{x, y}] + 1;
    }

    posx = xs[x].lower_bound(y);
    if(posx != xs[x].begin()) {
      posx--;
      if(*posx+1 < y && dist.find({x, *posx+1}) == dist.end()) {
        q.emplace(x, *posx+1);
        dist[{x, *posx+1}] = dist[{x, y}] + 1;
      }
    }

    auto posy = ys[y].upper_bound(x);
    // se tiver algum x nessa reta, pegar o primeiro
    if(posy != ys[y].end() && 
       *posy-1 > x && 
       dist.find({*posy-1, y}) == dist.end()) {
        q.emplace(*posy-1, y);
        dist[{*posy-1, y}] = dist[{x, y}] + 1;
    }

    posy = ys[y].lower_bound(x);
    if(posy != ys[y].begin()) {
      posy--;
      if(*posy+1 < x && dist.find({*posy+1, y}) == dist.end()) {
        q.emplace(*posy+1, y);
        dist[{*posy+1, y}] = dist[{x, y}] + 1;
      }
    }
  }
  out(-1);
}
