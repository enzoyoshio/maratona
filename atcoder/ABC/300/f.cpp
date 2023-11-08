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

auto main() -> signed {
  fastio;

  int n, m, k;
  in(n, m, k);
  string s;
  cin >> s;

  int qt = 0;
  deque<int> posX;
  for(int i = 0; i < s.size(); i++)
      qt += s[i] == 'x';

  auto query = [&](int l, int r) {
	int right = (r+1 == posX.size() ? s.size() : posX[r+1]);
	int left = (l == 0 ? 0 : posX[l-1]+1);	
	return right - left;
  };

  // se for so uma string
  // tenho que checar para os intervalos de tamanho pequeno
  // faz o naive
  if(m <= 10) {
    auto cpy = s;
    for(int i = 1; i < m; i++) s += cpy;

    for(int i = 0; i < s.size(); i++) {
      if(s[i] == 'x')
        posX.push_back(i);
    }

    int ans = 0;
    for(int i = 0; i+k-1 < posX.size(); i++) {
      ans = max(ans, query(i, i+k-1)); 
    }
    out(ans);
    return 0;

  }

  // se eu tenho que tirar menos que a quantidade de uma string
  if(k == m * qt) return cout << m*n << endl, 0;
  s += s;

  if(qt == 1) {
    int ans = n * k;
    int pos = 0;
    for(int i = 0; i < s.size(); i++) {
	if(s[i] == 'x') {
		pos = i;
		break;
	}
    }
    if(k >= 3) ans += n-1;
    else if(k == 2) ans += max(pos, n-1-pos);
    out(pos);
    return 0;
  }

  for(int i = 0; i < s.size(); i++) {
    if(s[i] == 'x') posX.push_back(i);
  }
  int ans = 0;

  int pega = k%qt;
  for(int i = 0; i <= qt;i++) {

    ans = max(ans,
	(pega == 0 ? 0 : posX[i+pega] - posX[i])
	+ posX[i]
	- (i == 0 ? 0 : posX[i-1]+1)
	);
  }
  out(ans + (k/qt) * n);

}
// 94216784100001
// 94216784100000 
