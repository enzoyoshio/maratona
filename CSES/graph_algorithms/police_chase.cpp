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

const int INF = 1e18;

struct Dinitz {
  struct Edge {
    int v, u, cap, flow=0;
    Edge (int v, int u, int cap) : v(v), u(u), cap(cap) {}
  };

  vector<Edge> edges;
  vector<vector<int>> adj;

  int n, s, t;
  Dinitz(int n, int s, int t) : n(n), s(s), t(t) {
    adj.resize(n);
  }

  void add_edge(int v, int u, int cap) {
    edges.emplace_back(v, u, cap);
    adj[v].push_back(edges.size()-1);
    edges.emplace_back(u, v, 0);
    adj[u].push_back(edges.size()-1);
  }

  vector<int> level;
  bool bfs() {
    queue<int> Q;
    level.assign(n, -1);
    level[s] = 0;
    Q.push(s);
    while (!Q.empty()) {
      int v = Q.front(); Q.pop();
      for (auto eid : adj[v]) {
        auto e = edges[eid];
        if (e.cap - e.flow <= 0) continue;
        if (level[e.u] != -1) continue;
        level[e.u] = level[v] + 1;
        Q.push(e.u);
      }
    }
    return level[t] != -1;
  }

  vector<int> ptr;
  int dfs(int v, int f) {
    if (f == 0 || v == t) return f;
    for (int &cid = ptr[v]; cid < adj[v].size(); cid++) {
      int eid = adj[v][cid];
      auto &e = edges[eid];
      if (e.cap - e.flow <= 0) continue;
      if (level[e.u] != level[e.v] + 1) continue;
      int newf = dfs(e.u, min(f, e.cap-e.flow));
      if (newf == 0) continue;
      e.flow += newf;
      edges[eid^1].flow -= newf;
      return newf;
    }
    return 0;
  }

  int flow() {
    int f = 0;
    while (bfs()) {
      ptr.assign(n, 0);
      while (int newf = dfs(s, INF))
        f += newf;
    }
    return f;
  }
};

auto main() -> signed {
  fastio;

  int n, m;
  in(n, m);
  Dinitz d(n, 0, n-1);

  for(int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    a--, b--;
    d.add_edge(a, b, 1);
  }

  cout << d.flow() << endl;

  V<ii> ff, tt;
  for(auto [from, to, cap, fl]: d.edges) {
    if(from == d.s && fl == 1)
      ff.emplace_back(from, to);
    if(to == d.t && fl == 1)
      tt.emplace_back(from, to);
  }

  if(tt.size() > ff.size()) swap(tt, ff);

  for(auto [a, b]: ff)
    cout << a+1 << ' ' << b+1 << endl;


}
