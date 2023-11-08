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

const int MAX = 5e3+9;

V<int> f(MAX);
int f1(int idx, int mex) {

  if(!idx) {
    cout << endl << endl;
    cout << "state " << idx << ' ' << mex << endl;
    cout << f[idx] << ' ' << mex << ' ' << f[idx] * mex << endl;
    return (f[idx]-1) * mex;
  }

  int npega = f1(idx-1, mex);

  int pega = f1(idx-1, idx) + (f[idx]-1)*mex + idx;

  cout << endl << endl;
  cout << "state " << idx << ' ' << mex << endl;
  cout << "pega = " << pega << " npega = " << npega << endl;
  return min(pega, npega);
}

auto main() -> signed {
  fastio;

  int t; cin >> t; while(t--) {
    int n; cin >> n;
    V<int> v(n);
    f.clear();
    f.resize(MAX);
    for(auto& it: v) {
      cin >> it;
      if(it < MAX) f[it]++;
    }

    int mex = 0;
    for(int i = 0; i < MAX; i++) {
      if(!f[i]) {
        mex = i;
        break;
      }
    }

    if(!mex) {
      cout << 0 << '\n';
      continue;
    }

    /*
    cout << "mex = " << mex << endl;
    cout << f1(mex-1, mex) << endl;
    */

    V<V<int>> dp(mex+2, V<int>(mex+2));

    for(int i = 0; i <= mex; i++)
      dp[0][i] = i * (f[0]-1);

    for(int idx = 1; idx < mex; idx++) {
      for(int mexc = idx; mexc <= mex; mexc++) {
        dp[idx][mexc] = min(dp[idx-1][mexc], dp[idx-1][idx] + (f[idx]-1)*mexc + idx);
      }
    }
    cout << dp[mex-1][mex] << '\n';
  }
}
