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

struct no {
  int maxi;
  int cost;
  int tam;

  no() : maxi(0), cost(0), tam(0) {}
  no(int val) : maxi(val), cost(0), tam(1) {}
  no(int ma, int co, int ta) : maxi(ma), cost(co), tam(ta) {}
};

struct ST {
  V<no> st;
  int n;

  ST() {}

  ST(int _n) : n(_n) {
    st.resize(4*n);
  }

  no merge(no a, no b) {
    if(b.maxi >= a.maxi)
      return no(b.maxi, a.cost + b.cost, a.tam + b.tam);
    return no(a.maxi, a.cost + b.cost + abs(b.maxi-a.maxi)*b.tam, a.tam+b.tam);
  }

  no update(int id, int v, int sti, int stl, int str) {
    if(id < stl || id > str) return st[sti];
    if(stl == str)
      return st[sti] = no(v, 0, 1);
    int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;
    return st[sti] = merge(update(id, v, ste, stl, stm), update(id, v, std, stm+1, str));
  }
  no update(int id, int v) {
    return update(id, v, 1, 0, n-1);
  }

  no query(int L, int R, int sti, int stl, int str) {
    if(L > str || stl > R) return no(0, 0, 0);

    if(L <= stl && str <= R) return st[sti];
    int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;
    return merge(query(L, R, ste, stl, stm), query(L, R, std, stm+1, str));
  }
  no query(int L, int R) {
    return update(L, R, 1, 0, n-1);
  }
};

auto main() -> signed {
  fastio;

  int n, q;
  cin >> n >> q;
  ST st(n);
  for(int i = 0; i < n; i++) {
    int a; cin >> a;
    st.update(i, a);
  }
  for(int i = 0; i < q; i++) {
    int a, b; cin >> a >> b;
    a--, b--;
    cout << st.query(a, b).cost << '\n';
  }
}
