#include <bits/stdc++.h>
using namespace std;

// Template (v1.4.2 - 2023-04-22) (codeforces:cebolinha, atcoder:edu) {{{

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
using iii = tuple<int,int,int>;

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

  int n, m;
  cin >> n >> m;
  vector<pair<int,int>> g[n];

  for(int i = 0; i < m; i++) {
    int a, b, c; cin >> a >> b >> c; a--, b--;
    g[a].emplace_back(b, c);
  }

  vector<vector<int>> dist(n, vector<int>(2, oo));
  min_priority_queue<iii> pq;
  pq.emplace(0, 0, 0);
  dist[0][0] = 0;
  dist[0][1] = 0;

  while(pq.size()) {
    auto [custo, idx, desconto] = pq.top(); pq.pop();

    if(custo > dist[idx][desconto]) continue;

    for(auto [no, peso]: g[idx]) {

      // se eu ja apliquei o desconto,
      // nao tem como aplicar denovo,
      // so tenho uma opcao
      if(desconto) {
        if(custo + peso < dist[no][desconto]) {
          dist[no][desconto] = custo + peso;
          pq.emplace(dist[no][desconto], no, desconto);
        }
      }else {

        // aqui eu posso escolher entre aplicar ou nao o descont

        // se eu nao aplicar desconto
        if(custo + peso < dist[no][0]) {
          dist[no][0] = custo + peso;
          pq.emplace(dist[no][0], no, 0);
        }

        // se eu aplicar o desconto nessa aresta
        if(custo + peso/2 < dist[no][1]) {
          dist[no][1] = custo + peso/2;
          pq.emplace(dist[no][1], no, 1);
        }
      }
    }
  }
  cout << min(dist[n-1][0], dist[n-1][1]) << endl;
}


