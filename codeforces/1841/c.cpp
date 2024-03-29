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

const int oo = 1e16;
const int MAXN = 2e5+8;
string s;
int n;
map<char, int> m = {
  {'A', 1},
  {'B', 10},
  {'C', 100},
  {'D', 1000},
  {'E', 10000},
};
V<V<V<int>>> tb(MAXN, V<V<int>>(5, V<int>(2)));

int custo(int a, int b) {
  if(a < b) return -m[char('A'+a)];
  return m[char('A'+a)];
}

int dp(int idx, int max_suf, bool changed) {
  
 // db(var(idx), var(max_suf), var(changed));
  if(idx < 0) {
    return 0;
  }

  auto& ans = tb[idx][max_suf][changed];
  if(ans > -oo) return ans;
  
  int nao_troca = 
    custo(s[idx]-'A', max_suf) + 
    dp(idx-1, max((int)s[idx]-'A', max_suf), changed);

  int troca = -oo;
  if(!changed) {
    for(int i = 0; i < 5; i++) {
      if(i == s[idx]-'A') continue;
      troca = max(troca, 
          custo(i, max_suf) + dp(idx-1, max(i,max_suf), 1)); 
    }
  }

  /*
  cerr << endl << endl;
  db(var(idx), var(max_suf), var(changed));
  db(var(troca), var(nao_troca));
  */
  
  return ans = max(troca, nao_troca);
}

auto main() -> signed {
  fastio;

  int t; in(t); while(t--) {
    in(s); n = sz(s);

    //db(var(s));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < 5; j++) {
        tb[i][j][0] = -oo;
        tb[i][j][1] = -oo;
      }
    }
    //db(var(s));

    //db(var("oioioi"));
//    out(max(dp(n-1, 0, 0), dp(n-1, 0, 1)));

    out(dp(n-1, 0, 0));
  }
}
