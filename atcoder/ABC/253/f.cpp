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

struct ST {
	V<int> st;
	int n;

	ST(int n) : n(n), st(4*n) {}

	int update(int id, int v, int sti, int stl, int str) {
		if(id > str || id < stl) return st[sti];

		if(stl == str) return st[sti] += v;

		int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;
		return st[sti] = update(id, v, ste, stl, stm) +
				 update(id, v, std, stm+1, str);
	}
	int update(int id, int v) { return update(id, v, 1, 0, n-1);}

	int query(int L, int R, int sti, int stl, int str) {
		if(L > str || stl > R) return 0;

		if(L <= stl && str <= R) return st[sti];

		int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;
		return query(L, R, ste, stl, stm) + query(L, R, std, stm+1, str);
	}
	int query(int L, int R) { return query(L, R, 1, 0, n-1);}
};

auto main() -> signed {
  fastio;

  int n, m, q;
  in(n, m, q);

  V<iii> queries(q);
  V<V<int>> need(q);
  V<int> last_row_change(n, -1);
  V<ii> ans;
  V<int> type(q);

  for(int i = 0; i < q; i++) {
	int t; in(t);
	type[i] = t;

	if(t == 1) {
		int l, r, x;
		in(l, r, x);
		l--, r--;

		queries[i] = {l, r, x};
	}else if(t == 2) {
		int id, x;
		in(id, x);
		id--;

		queries[i] = {id, x, 0};
		last_row_change[id] = i;
	}else {
		int id, j;
		in(id, j);
		id--, j--;
		if(last_row_change[id] != -1)
			need[last_row_change[id]].push_back(ans.size());
		queries[i] = {id, j, ans.size()};
		ans.emplace_back(j, 0);
	}
  }

  ST st(m);
  for(int i = 0; i < q; i++) {
	int t = type[i];
	if(t == 1) {
		auto [l, r, x] = queries[i];
		st.update(l, x);
		if(r+1 < m) st.update(r+1, -x);
	}else if(t == 2) {
		for(auto id: need[i]) {
			ans[id].second = queries[i][1] - st.query(0, ans[id].first);
		}
	}else {
		ans[queries[i][2]].first = st.query(0, queries[i][1]);
	}
  }

  for(auto [a, b]: ans) cout << a+b << '\n';
}
