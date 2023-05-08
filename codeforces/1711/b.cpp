#include <bits/stdc++.h>
using namespace std;

// Template (v1.4.0 - 2023-04-19) (codeforces:cebolinha, atcoder:edu) {{{

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
template<class C, typename T = typename C::value_type> auto &operator>>(istream &is, C &c) { for (auto &x : c) is >> x; return is; }
template<class C, typename T = typename C::value_type> auto &operator<<(ostream& os, C const &c) { auto sep = EMPTY_STRING; for (auto x : c) os << sep << x, sep = SEPARATOR; return os; }

template<class... A> void in(A &...a) { ((cin >> a), ...); }
template<class... A> void out(A const&... a) { auto sep = EMPTY_STRING; ((cout << sep << a, sep = SEPARATOR), ...); cout << '\n'; }
template<class... A> void print(A const&... a) { ((cout << a), ...); }
#define var(x) "[", #x, " ", x, "] "
template<class... A> void db(A const&... a) { ((cout << (a)), ...); cout << endl; }
//}}}

auto main() -> signed {
  fastio;

  int t;
  in(t);
  while(t--) {
	  int n, m;
	  in(n, m);
	  vector<int> v(n), freq(n), notF(n);
	  vector<pair<int,int>> par(m);
	  in(v);
	 
	  for(int i = 0; i < m; i++) {
		int a, b; in(a, b); a--, b--;
		par[i] = {a, b};
		freq[a]++, freq[b]++;
	  }

	  if(m%2 == 0) {
		cout << 0 << endl;
		continue;
	  }

	  int ans = 1e5;
	  
	  for(auto [a, b]: par) {
		
		  /*
		  cout << "-------------\n";
		  cout << a << ' ' << b << endl;
		  */
		  if(freq[a]%2 == 0 && freq[b]%2 == 0) {
		//	  cout << v[a] << ' ' << v[b] << endl;
			  ans = min(ans, v[a] + v[b]);
		  }
	  }
	  
	  for(int i = 0; i < n; i++)
		  if(freq[i]%2) 
			  ans = min(ans, v[i]);
	  cout << ans << endl;
  }
}

