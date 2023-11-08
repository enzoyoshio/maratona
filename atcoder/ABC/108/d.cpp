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

// I need to 
auto main() -> signed {
  fastio;

  int n;
  cin >> n;

  if(n == 2) {
    cout << 2 << ' ' << 2 << endl;
    cout << 1 << ' ' << 2 << ' ' << 0 << endl;
    cout << 1 << ' ' << 2 << ' ' << 1 << endl; 
    return 0;
  }

  if(n == 3) {
    cout << 2 << ' ' << 3 << endl;
    cout << 1 << ' ' << 2 << ' ' << 0 << endl;
    cout << 1 << ' ' << 2 << ' ' << 1 << endl; 
    cout << 1 << ' ' << 2 << ' ' << 2 << endl; 
    return 0;
  }

  if(n == 4) {
    cout << 2 << ' ' << 4 << endl;
    cout << 1 << ' ' << 2 << ' ' << 0 << endl;
    cout << 1 << ' ' << 2 << ' ' << 1 << endl; 
    cout << 1 << ' ' << 2 << ' ' << 2 << endl; 
    cout << 1 << ' ' << 2 << ' ' << 3 << endl; 
    return 0;
  }

  n--;
  int last = 63 - __builtin_clzll(n);

  vector<int> idx, rest;
  for(int i = 0; i <= last; i++) {
    if(n&(1 << i)) idx.eb(i);
    else rest.eb(i);
  }

  vector<iii> edg;
  int available = 2;

  for(int i = 0; i < last; i++) {
    edg.pb({available-1, available, 1 << i});
    edg.pb({available-1, available, 0});
    available++;
  }

  bool first = true;
  for(auto on: idx) {
    if(first) {
      first = false;

      // or I am obligated to follow 
      // who is turned on
      edg.pb({1, available, 1 << on});
      // or I can make all the submask of on-1
      edg.pb({on+1, available, 0});
      available++;
      continue;
    }
    edg.pb({available-1, available, 1 << on});
    edg.pb({on+1, available, 0});
    available++;
  }

//  assert(available <= 21);

  while(available <= 20)
    edg.pb({available-1, available++, 0});
  
 // assert(edg.size() <= 60);

  cout << 20 << ' ' << edg.size() << endl;
  for(auto [a, b, c]: edg) cout << a << ' ' << b << ' ' << c << endl;
}
