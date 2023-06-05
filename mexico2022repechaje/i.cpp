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

const int MAXN = 5e5+8;
const int oo = 1e10;
int n, c = 0;
vector<pair<int,int>> st;
vector<int> v, qry(MAXN);

pair<int,int> build(int sti=1, int stl=0, int str=n-1) {

  if(stl == str) return st[sti] = {v[stl], stl};

  int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;

  return st[sti] = max(build(ste, stl, stm), build(std, stm+1, str));
}

pair<int,int> update(int val, int id, int sti=1, int stl=0, int str=n-1) {
  
  if(stl > id || str < id) return {0, -1};

  if(stl == str) return st[sti] = {val, id};

  int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;

  return st[sti] = max(update(val, id, ste, stl, stm), update(val, id, std, stm+1, str));
}

pair<int,int> query(int ql, int qr, int sti=1, int stl=0, int str=n-1) {

  if(ql > str || qr < stl) return {0, -1};

  if(ql <= stl && str <= qr) return st[sti];

  int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;

  return max(query(ql, qr, ste, stl, stm), query(ql, qr, std, stm+1, str));
}

int rec(int l, int r) {
  
//  if(c++ > 10) return 0;

  if(l > r) return 0;
  if(l == r) return v[qry[l]];

  // idx -> of vector v
  auto [maxi, idx] = query(qry[l], qry[r]);

  // same -> of vector qry
  auto same = lower_bound(begin(qry)+l, begin(qry)+r+1, idx) - (begin(qry));

  if(r-l == 1)
    return v[qry[l]] + v[qry[r]] + maxi;

  /*
  db(var(l));
  db(var(r));
  db(var(maxi));
  db(var(same));
  db(var(idx));
  cerr << "\n\n";
  */

  int ans = 0;
  int sz = r-l+1;
  int pre = same-l;
  // se o maior for um dos idx
  if(qry[same] == idx) {
   // db(var(sz-same+1));
    ans += (pre+1) * (sz-pre) * maxi;
    ans += rec(l, same-1);
    ans += rec(same+1, r); 
  }else {
    ans += (pre) * (sz-pre) * maxi;
    ans += rec(l, same-1);
    ans += rec(same, r);
  }
  return ans;
}

auto main() -> signed {
  fastio;

  in(n);
  v.resize(n);
  st.resize(4*n);
  in(v);

  build();

  int q; in(q);
  while(q--) {
    int tam; in(tam);

    for(int i = 0; i < tam; i++)
      cin >> qry[i], qry[i]--;

    cout << rec(0, tam-1) << '\n';
  }
}
