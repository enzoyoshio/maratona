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

struct ST {
  V<ii> st;
  int n;
  ii el_n = {oo, oo};

  ST(int n) : n(n) {
    st.resize(4*n);
  }

  ii f(ii a, ii b) {
    return {min(a.first, b.first), a.second + b.second};
  }

  ii update(int id, int x, int sti, int stl, int str) {
    if(id > str || id < stl) return st[sti];

    if(stl == str) { return st[sti] = {x, 1};}

    int stm = (stl + str)/2, ste = 2*sti, std = 2*sti+1;

    return f(update(id, x, ste, stl, stm), update(id, x, std, stm+1, str));
  }
  ii update(int id, int x) { return update(id, x, 1, 0, n-1);}

  ii query(int L, int R, int sti, int stl, int str) {
    if(L > str || stl > R) return el_n;

    if(L <= stl && str <= R) return st[sti];

    int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;

    return f(query(L, R, ste, stl, stm), query(L, R, std, stm+1, str));

  }
  ii query(int L, int R) { return query(L, R, 1, 0, n-1);}

  ii lower_bound(int until, int x, int sti, int stl, int str) {
    if(stl > until) return el_n;
    if(st[sti].first < x) return el_n;

    if(stl == str)
      return st[sti];

    int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;
    return f(lower_bound(until, x, ste, stl, stm), lower_bound(until, x, std, stm+1, str));

  }
  ii lower_bound(int until, int x) { 
    return lower_bound(until, x, 1, 0, n-1);
  }

};

auto main() -> signed {
  fastio;

  int n;
  cin >> n;
  V<int> v(2*n);
  in(v);
  for(auto& it: v) it--;

  ST st(2*n);

  vector pos(n, V<int>());

  for(int i = 0; i < 2*n; i++)
    pos[v[i]].eb(i);

  V<int> ans(n);

  V<int> pre(n, oo);
  for(int i = 0; i < 2*n; i++) {
    st.update(i, pre[v[i]]);
    pre[v[i]] = i;
  }

  for(int i = 0; i < n; i++) {
    cerr << "----------------- db -------------------\n";
    db(var(v[i]));
    db(var(i));
    db(var(pos[i][0]), var(pos[i][1]));
    db(var(st.lower_bound(pos[i][1], pos[i][0]).first));
    db(var(st.lower_bound(pos[i][1], pos[i][0]).second));

    ans[i] = st.lower_bound(pos[i][1], pos[i][0]).second - 
             (pos[i][1]-1 >= 0 ? st.lower_bound(pos[i][0]-1, pos[i][0]).second : 0);
  }

  out(ans);
}
