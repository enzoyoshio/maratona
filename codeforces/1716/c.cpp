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

const int oo = 1e17;

auto main() -> signed {
  fastio;

  int t; cin >> t; while(t--) {
    int n; cin >> n;
    vector<vector<int>> v(2, vector<int>(n));
    V<int> mini(n);
    in(v);

    int ans = oo;

    int cur = 0;
    for(int i = 0; i < n; i++) {
      int f = v[0][i], s = v[1][i];
      if(i%2) swap(f, s);

      if(cur < f) cur = f;
      if(i) cur++;
      if(cur < s) cur = s;
      cur++;
      mini[i] = cur;
    }
    //db(var(cur));
    ans = min(ans, cur);
    cur = 0;
    for(int i = 0; i < n; i++) {
      if(cur < v[0][i]) cur = v[0][i];
      if(i) cur++;
    }
    for(int i = n-1; i >= 0; i--) {
      if(cur < v[1][i]) cur = v[1][i];
      cur++;
    } 
    //db(var(cur));
    ans = min(ans, cur);
    cur = 0;
    for(int i = 0; i < n; i++) {
      int f = v[0][i], s = v[1][i];
      if(cur < s) cur = v[1][i];
      cur++;
    }
    for(int i = n-1; i; i--) {
      if(cur < v[0][i]) cur = v[0][i];
      cur++;
    }
    ans = min(ans, cur);

    int maxUp = n-1, maxDown = n-1;
    for(int i = n-2; i >= 0; i--) {
      
      /*
      db(var(i));
      db(var(maxUp));
      db(var(maxDown));
      db(var(v[0][maxUp]));
      db(var(v[1][maxDown]));
      */
      if(v[0][maxUp] >= v[1][maxDown]) {
        if(i%2) {
          //db(var(max(maxUp-i + mini[i], v[0][maxUp]+1) + n-1 - maxUp + n-1 - i));
          ans = min(ans, max(maxUp-i + mini[i], v[0][maxUp]+1) + n-1 - maxUp + n-1 - i);
        }else {
          //db(var(max(n-1- i + n-1 - maxUp + 1 + mini[i], v[0][maxUp]+1) + maxUp - i));
          ans = min(ans, max(n-1- i + n-1 - maxUp + 1 + mini[i], v[0][maxUp]+1) + maxUp - i);
        }
      }
      if(v[1][maxDown] >= v[0][maxUp]) {
        if(i%2) {
          //db(var(max(n-1-i + n-1 - maxDown + 1 + mini[i], v[1][maxDown]+1) + maxDown - i));
          ans = min(ans, max(n-1-i + n-1 - maxDown + 1 + mini[i], v[1][maxDown]+1) + maxDown - i);
        }else {
          //db(var(max(maxDown - i + mini[i], v[1][maxDown]+1) + n-1- maxDown + n-1 - i + 1));
          ans = min(ans, max(maxDown - i + mini[i], v[1][maxDown]+1) + n-1- maxDown + n-1 - i + 1);
        }
      }

      if(v[0][i] >= v[0][maxUp]) maxUp = i;
      if(v[1][i] >= v[1][maxDown]) maxDown = i;

    }
    out(ans);
  }
}
