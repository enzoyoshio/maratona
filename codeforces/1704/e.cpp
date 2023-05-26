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

const int MOD = 998244353;

struct intMod {
  int n;

  intMod(): n(0) {}

  intMod(int n): n(n) {}

  intMod operator+(intMod const& o) {
    this->n = (o.n + this->n)%MOD;
    return *this;
  }

  void operator+=(intMod const& o) {
    *this = *this + o;
  }

  intMod operator-(intMod const& o) {
    this->n = ((this->n - o.n)%MOD + MOD)%MOD;
    return *this;
  }

  void operator-=(intMod const& o) {
    *this = *this - o;
  }

  intMod operator*(intMod const& o) {
    this->n = (this->n * o.n)%MOD; 
  }

  void operator*=(intMod const& o) {
    *this = *this * o;
  }

  bool operator<(intMod const& o) {
    return this->n < o.n;
  }

  bool operator<=(intMod const& o) {
    return this->n <= o.n;
  }

  bool operator>(intMod const& o) {
    return this->n > o.n;
  }

  bool operator>=(intMod const& o) {
    return this->n >= o.n;
  }

  bool operator==(intMod const& o) {
    return this->n == o.n;
  }

};

pair<intMod,intMod> merge(pair<intMod,intMod> a, pair<intMod,intMod> b) {
  if(a.first + a.second <= b.first)
    return b; 
  if(b.first + b.second <= a.first)
    return a;

  if(a.first == b.first) {

  }
  if(a.first > b.first)
    swap(a, b);
  a.first += b.first;
  a
  a.second += b.second;
  return a;
}

auto main() -> signed {
  fastio;
  
  int t; cin >> t; while(t--) {
    int n, m;
    in(n, m);
    vector<pair<intMod,intMod>> ans(n);
    for(auto& [a, b]: ans) {
      int num; cin >> num;
      b = intMod(num);
    }
    
    vector<int> indeg(n), outdeg(n);
    vector<vector<int>> g(n, vector<int>());

    for(int i = 0; i < m; i++) {
      int a, b; cin >> a >> b; a--, b--;
      indeg[b]++;
      outdeg[a]++;
      g[a].emplace_back(b);
    }

    // ordenacao topologica

    queue<int> q;
    // se ninguem chega nele, 
    // ele eh folha
    // comeca a cortar nele
    for(int i = 0; i < n; i++)
      if(indeg[i] == 0)
        q.push(i);

    while(q.size()) {
      auto u = q.front(); q.pop();

      cerr << "to processando o vertice " << u << endl;
      db(var(ans[u].first.n));
      db(var(ans[u].second.n));
      for(auto v: g[u]) {
        indeg[v]--;
        // fazer a logica aqui de passar
        ans[v] = merge(ans[v], ans[u]);
        db(var(v));
        db(var(ans[v].first.n));
        db(var(ans[v].second.n));
        // se todos os antecessores
        // tiverem sido processados
        // eu coloco ele pra processar
        if(!indeg[v]) {
          q.push(v);
        }
      }
    }

    for(int i = 0; i < n; i++) {
      if(outdeg[i] == 0) {
        cout << (ans[i].first + ans[i].second).n << endl;
        break;
      }
    }
  }
}
