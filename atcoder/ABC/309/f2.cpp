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

struct ST {
  vector<int> st;
  int n;

  ST(int _n) : n(_n), st(4*_n, oo) {}

  int update(int x, int v, int sti, int stl, int str) {
    if(x > str || x < stl) return st[sti];

    if(stl == str) {
      miq(st[sti], v);
      return st[sti];
    }

    int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;
    return st[sti] = min(update(x, v, ste, stl, stm),
                         update(x, v, std, stm+1, str));
  }
  int update(int x, int v) { return update(x, v, 1, 0, n-1);}

  int query(int A, int B, int sti, int stl, int str) {
    if(B < A) return oo;
    if(A > str || stl > B) return oo;

    if(A <= stl && str <= B) return st[sti];

    int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;
    return min(query(A, B, ste, stl, stm), query(A, B, std, stm+1, str));
  }
  int query(int A, int B) { return query(A, B, 1, 0, n-1);}
};

auto main() -> signed {
  fastio;

  int n;
  in(n);
  V<iii> v(n);
  map<int,vector<ii>> stu;
  V<int> ord;
  for(auto& [a, b, c]: v) {
    in(a, b, c); 
    ord.eb(a); ord.eb(b); ord.eb(c);
  }
  for(auto& e: v) sort(begin(e), end(e));
  sort(begin(v), end(v), [](iii a, iii b) {
    auto [a1, a2, a3] = a;
    auto [b1, b2, b3] = b;

    return (a1 < b1) || (a1 == b1 && a2 > b2) || (a1 == b1 && a2 == b2 && a3 < b3);    
  });
  sort(begin(ord), end(ord));
  // the first one will be already satsifying the condition

  auto fi = [&](int x) {
    return lower_bound(begin(ord), end(ord), x)-begin(ord);
  };
  
  ST st(3*n);

  bool can = false;
  for(auto [a, b, c]: v) {
    can |= st.query(0, fi(b)-1) < c;
    st.update(fi(b), c);
  }
  out(cond(can, "Yes", "No"));
}
