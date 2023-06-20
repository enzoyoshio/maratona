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

const int EPS = 1e5;

int n, m, k;
V<ii> taka, aoki;

int check(int val) {
  int qt = 0;

  V<int> dbg;
  for(auto [a, b]: taka) {
    for(auto [i, j]: aoki) {
      if(val < (a+i)*EPS*EPS/(a+b+i+j)) qt++;
      dbg.eb((a+i)*EPS*EPS/(a+b+i+j)); 
    }
  }
  db(var(dbg));
  return qt;

  for(auto [a, b]: taka) {
    int tl = 0, tr = m-1, ans = m;
    while(tl <= tr) {
      int tmid = (tl+tr)/2;
      auto [i, j] = aoki[tmid];

      if(val < (a+i)*EPS*EPS/(a+i+b+j)) tr = tmid-1, ans = tmid;
      else tl = tmid+1;
    }
    qt += m-ans;
  }
  return qt;
}

auto main() -> signed {
  fastio;

  in(n, m, k);
  taka.resize(n), aoki.resize(m);
  in(taka, aoki);
  if(n > m) swap(n, m), swap(taka, aoki);

  // sorting by concentration of sugar
  auto comp = [](ii a, ii b) {
    auto [x, y] = a;
    auto [i, j] = b;
    return x*(i+j) < i*(x+y);
  };

  sort(all(taka), comp);
  sort(all(aoki), comp);

  // get maximum possible answer
  int l = (int)EPS, r = (int)EPS*EPS, ans = 0;

  while(l <= r) {
    int mid = (l+r)/2;
    int qt = check(mid);
    cerr << "\n\n---------------- db ----------------\n";
    db(var(l), var(r));
    db(var(mid));
    db(var(ans));
    db(var(qt));

    // check -> retorna true
    // se quantidade de elementos maiores que mid
    // for maior q k
    // aumenta o L e pega ele como resposta
    if(qt < k) r = mid-1, ans = mid;
    else l = mid+1; // nao tem k 
  }

  int resposta = ans;
  /*
  for(auto [a, b]: taka) {
    for(auto [i, j]: aoki) {
      int val = (a+i)*EPS*EPS/(a+b+i+j); 
      if(val < ans) resposta = max(resposta, val);
    }
  }
  */

  V<int> pares;
  for(auto [a, b]: taka) {
    for(auto [i, j]: aoki) {
      pares.eb((a+i)*EPS*EPS/(a+b+i+j));
    }
  }

  sort(all(pares));
  out(pares);
  string s = to_string(resposta);
  cout << s.substr(0, 2) << '.' << s.substr(2) << endl;
}
