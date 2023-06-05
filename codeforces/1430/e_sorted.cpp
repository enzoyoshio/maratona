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

struct ST {
  V<int> st;
  int n;

  ST(int _n) {
    n = _n;
    st.resize(4*n); 
  }

  int query(int L, int R, int sti, int stl, int str) {
    if(L > R) return 0;
    if(L > str || stl > R) return 0;

    if(stl <= L && R <= str) return st[sti];

    int stm = (stl+str)/2, ste = 2*sti, std = 2*sti + 1;

    return query(L, R, ste, stl, stm) + query(L, R, std, stm+1, str);
  }
  int query(int L, int R) { return query(L, R, 1, 0, n-1);}

  int update(int pos, int val, int sti, int stl, int str) {
    if(stl > pos || pos > str) return 0;

    if(stl == str) return db(var(pos), var(val), var(stl)), st[sti] += val;

    int stm = (stl + str)/2, ste = 2*sti, std = 2*sti+1;

    return st[sti] = update(pos, val, ste, stl, stm) + update(pos, val, std, stm+1, str);

  }
  int update(int pos, int val) { return update(pos, val, 1, 0, n-1);}
};

auto main() -> signed {
  fastio;

  int n; in(n);
  string s; in(s);
  string rev = s;
  reverse(all(rev));

  V<int> pos[26];
  for(int i = 0; i < n; i++) {
    pos[rev[i]-'a'].eb(i);
  }
  for(int i = 0; i < 26; i++)
    reverse(all(pos[i]));

  V<int> v(n);
  for(int i = 0; i < n; i++) {
    v[i] = pos[s[i]-'a'].back();
    pos[s[i]-'a'].pop_back();
  }

  ST st(n);

  db(var(v));
  int ans = 0;
  for(int i = n-1; i >= 0; i--) {
    db(var(v[i]));
    db(var(st.query(0, 0)));
    db(var(st.query(0, v[i]-1)));
    ans += st.query(0, v[i]-1);
    st.update(v[i], 1);
  }

  out(ans);
}
