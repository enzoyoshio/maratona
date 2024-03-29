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

/*
int dp(int i=0, int j=0, int bit=0) {
  if(i >= n || j >= n) return 0;
  if(i == n-1 && j == n-1) {
    res += (bit ^ grid[i][j]) == 0;
    return (bit ^ grid[i][j]) == 0;
  }
  if(ans.find(iii{i, j, bit}) != ans.end()) return ans[{i, j, bit}];
  return ans[{i, j, bit}] = dp(i+1, j, bit ^ grid[i][j]) + dp(i, j+1, bit ^grid[i][j]);
}
*/

int n; 
V<V<int>> grid;
vector from(20, V<unordered_map<int,int>>(20));
vector low(20, V<unordered_map<int,int>>(20));

auto main() -> signed {
  fastio;

  int res = 0;
  in(n);
  grid.resize(n, V<int>(n));
  in(grid);


  from[0][0][grid[0][0]] = 1;
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
		/*
		cerr << "\n\ndebugging from\n";
		db(var(i), var(j));
		db(var(from[i][j]));
		*/
		for(auto [xorsum, qt]: from[i][j]) {
			if(i+1 < n)
				from[i+1][j][xorsum^grid[i+1][j]] += qt;
			if(j+1 < n)
				from[i][j+1][xorsum^grid[i][j+1]] += qt;
		}
		if(j+i == n-1) break;
	}
  }

  low[n-1][n-1][grid.back().back()] = 1;
  for(int i = n-1; i >= 0; i--) {
	for(int j = n-1; j >= 0; j--) {
		/*
		cerr << "\n\ndebugging low\n";
		db(var(i), var(j));
		db(var(low[i][j]));
		*/
		for(auto [xorsum, qt]: low[i][j]) {
			if(i-1 >= 0)
				low[i-1][j][xorsum^grid[i-1][j]] += qt;
			if(j-1 >= 0)
				low[i][j-1][xorsum^grid[i][j-1]] += qt;
		}
		if(j+i == n-1) break;
	}
  }

  for(int i = 0; i < n; i++) {
	  int j = n-1-i;
	  for(auto [xorsum, qt]: from[i][j]) {
	
		if(i+1 < n && low[i+1][j].find(xorsum) != end(low[i][j]))
		{
	/*	
			cerr << "\n\nmergeando na pos " << endl;
			db(var(i), var(j));
			db(var(xorsum));
			db(var(qt), var(low[i+1][j][xorsum]));
			*/
		       res += qt * low[i+1][j][xorsum];	
		}

		
		if(j+1 < n && low[i][j+1].find(xorsum) != end(low[i][j+1]))
		{
			/*
			cerr << "\n\nmergeando na pos " << endl;
			db(var(i), var(j));
			db(var(xorsum));
			db(var(qt), var(low[i][j+1][xorsum]));
			*/
		       res += qt * low[i][j+1][xorsum];	
		}
	  }
  }
//  db(var(res));
  out(res);
}
