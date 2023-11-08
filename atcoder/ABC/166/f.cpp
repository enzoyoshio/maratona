#include <bits/stdc++.h>
<<<<<<< HEAD
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

  int n;
  cin >> n;
  vector<int> qt(3), paridade(3), ans(n), counter(3);
  vector<iii> v(n);

  for(auto& it: qt) cin >> it;

  for(int i = 0; i < n; i++) {
    string s; cin >> s;
    v[i][0] = s[0] - 'A';
    v[i][1] = s[1] - 'A';
    v[i][2] = i;

    // sort by A -> B -> C
    if(v[i][0] > v[i][1]) swap(v[i][0], v[i][1]);

    paridade[v[i][1]]++;
    paridade[v[i][0]]++;
  }

  bool par = 1;
  for(auto p: paridade) par &= !(p%2), db(var(p));

  sort(begin(v), end(v));

  // se for par, sempre da, so tem que distribuir da melhor forma
  if(par) {
    cerr << "entrei aqui\n";
    for(auto [ch1, ch2, id]: v) {
      if(counter[ch1] < paridade[ch1]/2) {
        db(var(id), var(ch1));
        ans[id] = ch1;
        counter[ch1]++;
      }else {
        db(var(id), var(ch2));
        ans[id] = ch2;
        counter[ch2]++;
      }
    }
  }else {
    // se tiver dois impares, checar se o maior deles tem que ser maior que zero
    // se for maior que zero, tem resposta, se nao, nao tem resposta

  }

  cout << "Yes\n";
  for(auto it: ans) cout << char('A'+it) << '\n';
=======

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vector<string> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}

	// se eh tudo zero, entao nao tem jeito
	// alguem vai ficar negativo
	if(a + b + c == 0) return cout << "No\n", 0;

	vector cur{a, b, c};
	string ans = "";

	for(int i = 0; i < n; i++) {

		if(cur[0] < 0 || cur[1] < 0 || cur[2] < 0) return cout << "No\n", 0;
	
		// se tem so um cara positivo
		if(accumulate(begin(cur), end(cur), 0) == 1) {
			// se os dois que eu tenho que alterar sao zero, 
			// entao eh impossivel pq um dos dois fica negativo

			if(!cur[v[i][0]-'A'] && !cur[v[i][1]-'A']) return cout << "No\n", 0;
			// se um dos dois eh positivo eu so flipo eles
			if(cur[v[i][0]-'A']) {
				ans += v[i][1];
				cur[v[i][0]-'A']--;
				cur[v[i][1]-'A']++;
			}else {
				ans += v[i][0];
				cur[v[i][0]-'A']++;
				cur[v[i][1]-'A']--;
			}
		}else {
		// nesse else a soma >= 2
			if(!cur[v[i][0]-'A'] && !cur[v[i][1]-'A']) return cout << "No\n", 0;

			// se um dos dois for zero, entao eu sou obrigado
			if(!cur[v[i][0]-'A'] && cur[v[i][1]-'A']) {
				cur[v[i][0]-'A']++;
				cur[v[i][1]-'A']--;
				ans += v[i][0];
			}else if(cur[v[i][0]-'A'] && !cur[v[i][1]-'A']) {
				cur[v[i][1]-'A']++;
				cur[v[i][0]-'A']--;
				ans += v[i][1];
			}else if(accumulate(begin(cur), end(cur), 0) == 2 && cur[v[i][0]-'A'] && cur[v[i][1]-'A'] && i+1 < n && v[i] != v[i+1]) {

				if(v[i][0] == v[i+1][0] || v[i][0] == v[i+1][1]) {
					cur[v[i][0]-'A']++;
					cur[v[i][1]-'A']--;
					ans += v[i][0];
				}else {
					cur[v[i][1]-'A']++;
					cur[v[i][0]-'A']--;
					ans += v[i][1];
				}
				
			}else {
				if(cur[v[i][0]-'A'] < cur[v[i][1]-'A']) {
					cur[v[i][0]-'A']++;
					cur[v[i][1]-'A']--;
					ans+=v[i][0];
				}else {
					cur[v[i][1]-'A']++;
					cur[v[i][0]-'A']--;
					ans+=v[i][1];

				}
			}
		}
	}
	if(cur[0] < 0 || cur[1] < 0 || cur[2] < 0) return cout << "No\n", 0;

	cout << "Yes\n";
	for(auto ch: ans) cout << ch << '\n';
>>>>>>> e1ffc2a (mais sol no windows)
}
