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

  int t; in(t); while(t--) {
    string s; in(s);
    int n = s.size();

    set<char> old;
    string possible, ans = "-1";
    for(int i = n-1; i >= 0; i--) {
      if(old.find(s[i]) == old.end()) 
        possible += s[i];
      old.insert(s[i]);
    }
    reverse(all(possible));

    V<V<int>> v(n, V<int>(26, 0));
    for(int i = 0; i < n; i++) {
      v[i][s[i]-'a'] = 1;
      if(i)
        for(int j = 0; j < 26; j++)
          v[i][j] += v[i-1][j];
    }

    auto query = [&](int l, int r, int id) {
      if(l == 0) return v[r][id];
      return v[r][id] - v[l-1][id];
    };

    for(int i = 0; i < n; i++) {
      int qt = 0, allSz = 0;
      for(int j = 0; j < 26; j++)
        qt += v[i][j] > 0, allSz += v[i][j];

   //   cerr << "\n\n\n";
    //  db(var(qt), old.size());
      if(qt == old.size()) {
        bool can = true;
        int start = i+1;
        int eraser = 0;
        string cur = s.substr(0, i+1);

        while(start < n && cur.size()) {
 //         db(var(start));
          bool has2break = false;

          for(int j = 0; !has2break && j < cur.size(); j++) {
            if(cur[j] == '0') continue;
            if(cur[j] == possible[eraser]) {
              cur[j] = '0'; continue;
            }

            if(cur[j] == s[start]) start++;
            else has2break = true;
          }
          if(has2break) break;
  //        db(var(cur));
          eraser++;
        }
//        db(var(start), var(eraser));
        if(start == n && eraser == possible.size()-1) { ans = s.substr(0, i+1); break; }
      }
    }

    if(ans == "-1") {
      out(-1);
      continue;
    }
    cout << ans << ' ' << possible << '\n';
  }
}
