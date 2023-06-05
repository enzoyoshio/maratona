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
template<class T> using Q = queue<T>;
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

const int MAXN = 19;
const int MAXV = 51;
const int oo = 1e5;
int n;
V<ii> v;
int tb[MAXV][1LL << MAXN];

bool check(V<ii>& v) {
  bool sorted = true;
  for(int i = 0; i+1 < n; i++)
    sorted &= v[i].first <= v[i+1].first;
  return sorted;
}

int dp(int cur=0, int bitmask=0) {
  if(__builtin_popcountll(bitmask) >= n) {
    return 0;
  }

  auto& ans = tb[cur][bitmask];
  if(~ans) return ans;
  ans = oo;

  int next_pos = __builtin_popcountll(bitmask);
  int used = 0;
  for(int i = 0; i < n; i++) {
    if(((bitmask >> i) & 1) != 0) {
      next_pos--;
      continue;
    }

    if(i%2 == next_pos%2) {
      if(v[i].first >= cur)
        ans = min(ans, abs(i-next_pos+used) + dp(v[i].first, bitmask | (1LL << i))); 
    }else {
      if(v[i].second >= cur)
        ans = min(ans, abs(i-next_pos+used) + dp(v[i].second, bitmask | (1LL << i)));
    } 

    /*
    cerr << "\n\n----------------------- oioioi----------------------------\n";
    db(var(cur));
    db(var(bitset<20>(bitmask)));
    db(var(i));
    db(var(next_pos));
    db(var(v[i].first));
    db(var(v[i].second));
    db(var(ans));
    */
  }

  return ans;
}

auto main() -> signed {
  fastio;

  mem(tb, -1);
  in(n);
  v.resize(n);
  for(int i = 0; i < n; i++) in(v[i].first);
  for(int i = 0; i < n; i++) in(v[i].second);

  auto res = oo;
  for(int i = 0; i < n; i++)
    res = min(res, i + dp(i%2 ? v[i].second : v[i].first, 1LL << i));

  if(res >= oo) return out(-1), 0;
  out(res/2);
}
