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

const int MAXN = 2e5+8;
vector<vector<int>> g(MAXN);
vector<int> tin(MAXN), tout(MAXN);
int TIMER = -1;

void tour(int cur, int pai) {

  tin[cur] = ++TIMER;

  for(auto filho: g[cur]) if(filho != pai) {
    tour(filho, cur);
  }

  tout[cur] = TIMER;
}

struct ST {
  vector<int> st;
  int n;

  ST(int _n) : n(_n) {
    st.resize(4*n);
  }

  int update(int id, int x, int sti, int stl, int str) {

    if(stl > id || str < id) return st[sti];

    if(stl == str) return st[sti] = x;

    int stm = (stl+str)/2, ste = (2*sti), std = (2*sti)+1;
    return st[sti] = update(id, x, ste, stl, stm) + update(id, x, std, stm+1, str);
  }

  int query(int ql, int qr, int sti, int stl, int str) {
    if(stl > qr || str < ql) return 0;

    if(ql <= stl && str <= qr) return st[sti];

    int stm = (stl+str)/2, ste = (2*sti), std = (2*sti)+1;

    return query(ql, qr, ste, stl, stm) + query(ql, qr, std, stm+1, str);
  }

  int query(int ql, int qr) {
    return query(ql, qr, 1, 0, n-1);
  }

  int update(int id, int x) {
    return update(id, x, 1, 0, n-1);
  }
};

auto main() -> signed {
  fastio;

  int n, m; cin >> n >> m;
  V<int> value(n); in(value);  

  for(int i=1; i < n; i++) {
    int a, b; cin >> a >> b, a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  tour(0, 0);
  ST st(n);
  for(int i = 0; i < n; i++)
    st.update(tin[i], value[i]);

  while(m--) {
    int t; cin >> t;

    if(t == 1) {
      int s, x; cin >> s >> x;
      s--;
      st.update(tin[s], x);
    }else {
      int s; cin >> s; s--;
      cout << st.query(tin[s], tout[s]) << endl;
    }
  }
}


