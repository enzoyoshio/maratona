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

const int oo = 1e9;

struct ST {
  V<int> st;
  int n;
  
  ST() {
    n = -1; // sei la
  }

  ST(int _n) {
    n = _n;
    st.resize(4*n);
  }

  void build(int _n) {
    n = _n;
    st.resize(4*n);
  }

  // point query
  int query(int x, int sti, int stl, int str) {
    
    if(stl > x || str < x) return 0;

    if(stl == str) return st[sti];
    
    int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;

    return st[sti] + query(x, ste, stl, stm) + query(x, std, stm+1, str);
  }
  int query(int x) { return query(x, 1, 0, n-1);}

  // range update
  int update(int L, int R, int x, int sti, int stl, int  str) {
    if(L > str || R < stl) return 0;

    if(L <= stl && str <= R) return st[sti] += x;

    int stm = (stl+str)/2, ste = 2*sti, std = 2*sti + 1;

    update(L, R, x, ste, stl, stm);
    update(L, R, x, std, stm+1, str); 
    return 0;
  }
  int update(int L, int R, int x) { return update(L, R, x, 1, 0, n-1);}

  // get first idx that is greater or equal to x
  int lower_bound(int x) {
    return lower_bound(x, 1, 0, n-1);
  }
  int lower_bound(int x, int sti, int stl, int str) {
    
    if(stl == str) {
      if(st[stl] >= x) return stl;
      return n;
    }
    // se todos os caras no range [stl, str] 
    // sao menores entao nao tem resposta
    if(x - st[sti] > 0) return n;
    else {
      int stm = (stl + str)/2, ste = 2*sti, std = 2*sti+1;

      return min(lower_bound(x - st[sti], ste, stl, stm), lower_bound(x - st[sti], std, stm+1, str));
    }
  }

  // get first idx that is greater to x
  int upper_bound(int x) {
    return upper_bound(x, 1, 0, n-1);
  }
  int upper_bound(int x, int sti, int stl, int str) {
    
    if(stl == str) {
      if(st[stl] > x || st[stl] < 0) return stl;
      return n;
    }
    // se todos os caras no range [stl, str] 
    // sao menores entao nao tem resposta
    if(x - st[sti] >= 0 || st[stl] < 0) return n;
    else {
      int stm = (stl + str)/2, ste = 2*sti, std = 2*sti+1;

      return min(upper_bound(x - st[sti], ste, stl, stm), upper_bound(x - st[sti], std, stm+1, str));
    }
  }


};

auto main() -> signed {
  fastio;

  int n; in(n);
  string s; in(s);
  string rev = s;
  reverse(all(rev));

  if(s == rev) return out(0), 0;

  V<int> v[26];
  for(int i = 0; i < n; i++) {
    v[s[i]-'a'].eb(i);
  }

  V<ST> sts(26, ST());

  for(int i = 0; i < 26; i++) {
    sts[i].build(v[i].size());
    for(int j = 0; j < v[i].size(); j++) {
      sts[i].update(j, j, v[i][j]);
    } 
  }

  int ans = 0;
  for(int i = 0; i < n; i++) {
    int id = rev[i]-'a';
  
    // procurar na seg o primeiro que esteja 
    // mais proximo de i 
    int lower = sts[id].lower_bound(i);
    int val = sts[id].query(lower);

    db(var(lower));
    db(var(i));
    db(var(rev[i]));

    if(!lower) {
      sts[id].update(0, 0, -oo);
    }else {
      int pre = sts[id].query(lower-1);
      sts[id].update(lower, lower, pre-val);
    }

    // adicionando a resposta
    ans += val - i;

    cerr << "before adding\n";
    for(int j = 0; j < 26; j++) {
      db(var(id));
      cerr << "before adding 1\n";
      if(j == id) continue;
      
      cout << "got here\n";
      // get all that are in the range [i, lower]
      int lower1 = sts[j].lower_bound(i);
      int upper = sts[j].upper_bound(val);
      cout << "ended here\n";
      upper--;
      if(upper >= lower1)
        sts[j].update(lower1, upper, 1);
    }
  }

  out(ans);
}
