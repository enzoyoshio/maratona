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
#define var(x) "[", #x, " = ", x, "] "
template<class... A> void db(A const&... a) { ((cout << (a)), ...); cout << endl; }
//}}}

int n, q;
V<V<int>> arv;
V<int> tin, tout, st, psum, cost;
int TIMER = -1;

void euler(int u, int p) {
  tin[u] = ++TIMER;
  psum[u] = cost[u] + (p != -1 ? psum[p] : 0); 
  for(auto v: arv[u]) if(v != p) {
    euler(v, u);
  }
  tout[u] = TIMER;
}

void update(int ul, int ur, int val, int sti=1, int stl=0, int str=n-1) {
  if(ur < stl || ul > str) return;
  if(ul <= stl && str <= ur) {
    st[sti] += val;
    return;
  }
  int stm = (stl + str) /2 , ste = (2*sti), std = (2*sti) + 1;
  update(ul, ur, val, ste, stl, stm);
  update(ul, ur, val, std, stm+1, str);
}

int query(int x, int sti=1, int stl=0, int str=n-1) {
  if(stl > x || str < x) return 0;
  if(stl == str) return st[sti];
  int stm = (stl+str)/2, ste = (2*sti), std = (2*sti) +1;
  return st[sti] + query(x, ste, stl, stm) + query(x, std, stm+1, str);
}

auto main() -> signed {
  fastio;

  in(n, q);
  cost.resize(n);
  in(cost);
  arv.resize(n);
  st.resize(4*n, 0);
  psum.assign(n, 0);
  tin.resize(n);
  tout.resize(n);

  for(int i = 1; i < n; i++) {
    int a, b; in(a, b); a--, b--;
    arv[a].eb(b);
    arv[b].eb(a);
  }

  // fazer o euler tour
  euler(0, -1);

  // fazer a seg
  for(int i = 0; i < n; i++) {
    update(tin[i], tin[i], psum[i]);
  }

  while(q--) {
    int t, node;
    in(t, node);
    node--;

    // update
    if(t == 1) {
      int val; in(val);
      update(tin[node], tout[node], val - cost[node]);
      cost[node] = val;
    }else {
      out(query(tin[node]));
    }
  }
}
