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

const int oo = 1e11;
const int MAXL = 20;
using tiii = tuple<int,int,int>;
int n, q, TIMER = -1;
V<V<ii>> G;
V<int> tin, tout;
V<V<int>> parent;
V<int> st, lazy, soma;
V<tiii> edges;
map<ii, int> cost;

void prop(int sti, int stl, int str) {
  if(lazy[sti] == 0) return;

  st[sti] += (str-stl+1)*lazy[sti];
  if(stl != str) {
    lazy[2*sti] += lazy[sti];
    lazy[2*sti+1] += lazy[sti];
  }
  lazy[sti] = 0;
}

int update(int ll, int rr, int val, 
    int sti=1, int stl=0, int str=n) {
  prop(sti, stl, str);

  if(ll > str || rr < stl) return st[sti];

  if(ll <= stl && str <= rr) {
    lazy[sti] += val;
    prop(sti, stl, str);
    return st[sti];
  }

  int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;

  return st[sti] = update(ll, rr, val, ste, stl, stm) +
                   update(ll, rr, val, std, stm+1, str);
}

int query(int ll, int rr, int sti=1, int stl=0, int str=n) {
  prop(sti, stl, str);

  if(ll > str || rr < stl) return 0;

  if(ll <= stl && str <= rr) return st[sti];

  int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;

  return query(ll, rr, ste, stl, stm) 
    +    query(ll, rr, std, stm+1, str);
}

void dfs(int u, int v, int c) {
  tin[u] = ++TIMER;

  parent[u][0] = v;
  soma[u] = soma[v] + c;
  for(int i = 1; i < MAXL; i++) {
    parent[u][i] = parent[parent[u][i-1]][i-1];
  }

  for(auto [a, w]: G[u]) if(a != v) {
    dfs(a, u, w);
  }
  tout[u] = TIMER;
}

int is_ancestor(int u, int v) {
  return tin[u] < tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
  
  //db(var(u), var(v));
  if(is_ancestor(u, v)) {
    return  query(tin[v], tin[v]) -
            query(tin[u], tin[u]);
  }

  if(is_ancestor(v, u)) {
    return  query(tin[u], tin[u]) -
            query(tin[v], tin[v]);
  }

  int ans = query(tin[u], tin[u]) + query(tin[v], tin[v]);
  /*
  db(var(query(tin[u], tin[u])));
  db(var(query(tin[v], tin[v])));
  */

  for(int i = MAXL-1; i >= 0; i--) {
    if(!is_ancestor(parent[u][i], v)) u = parent[u][i];
  }
  /*
  cerr << "ancestor\n";
  db(var(parent[u][0]));
  db(var(query(tin[parent[u][0]], tin[parent[u][0]])));
  */

  return ans - 2*query(tin[parent[u][0]], tin[parent[u][0]]);
}

auto main() -> signed {
  fastio;

  in(n);
  G.resize(n+2);
  tin.resize(n+2);
  tout.resize(n+2);
  parent.assign(n+2, V<int>(MAXL));
  soma.resize(n+2);
  lazy.assign(4*(n+2), 0);
  edges.resize(n+1);
  for(int i = 1; i < n; i++) {
    int a, b, w; in(a, b, w);
    G[a].eb(b, w);
    G[b].eb(a, w);
    edges[i] = {a, b, w};
  }

  G[0].eb(1, 0); 
  dfs(0, 0, 0);
  st.resize(4*(n+2));

  for(int i = 1; i <= n; i++) {
    update(tin[i], tin[i], soma[i]);
  }

  in(q);
  while(q--) {
    int type, a, b; in(type, a, b);

    if(type == 1) {
      auto [u, v, w] = edges[a];
      if(parent[v][0] == u) swap(v, u);
      // idx, w
      int val = w;
      int diff = val-b;
      update(tin[u], tout[u], -diff);
      edges[a] = {u, v, b};
      soma[u] = -diff;
    }else {
      if(a == b) out(0);
      else
        out(lca(a, b));
    }
  }
}
