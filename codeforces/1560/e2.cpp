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

map<int,int> freq;
string possible;
string s;
V<int> qt;

string solve() {
    string ans = "-1";
    int tot = 0;
    for(int i = 0; i < qt.size(); i++) {
      tot += freq[possible[i]]/qt[i];
    }
    //db(var(tot));

    string cur = s.substr(0, tot);
    int idx = tot;
    int eraser = 0;

    while(idx < s.size() && cur != "") {
    
      string aux = "";
      for(auto ch: cur)
        if(ch != possible[eraser])
          aux += ch;
      cur = aux;

      /*
      db(var(s.size()));
      db(var(idx));
      db(var(cur));
      db(var(s.substr(idx, cur.size())));
      */
      if(s.substr(idx, cur.size()) != cur)
        break;
      idx += cur.size();
      eraser++;
    }

    if(idx == s.size()) {
      ans = s.substr(0, tot);
    }
    return ans;
}

auto main() -> signed {
  fastio;

  int t; in(t); while(t--) {
    freq.clear();
    possible = "";
    in(s);
    int n = s.size();

    set<char> old;
    for(int i = n-1; i >= 0; i--) {
      if(old.find(s[i]) == old.end()) 
        possible += s[i];
      old.insert(s[i]);
      freq[s[i]]++;
    }
    reverse(all(possible));

    V<int> eq(n, 1);
    for(int i = 1; i < n; i++)
      if(s[i] == s[i-1]) eq[i] += eq[i-1];

    bool pass = false;
    qt.resize(possible.size());
    string ans = "-1";

    int teste = freq[s.back()];
    //out(teste);
    for(int i = 1; i*i <= teste; i++) {
      if(ans != "-1") break;

      pass = false;
      // i = last i guys must be the same letter
      // and i should be divisible by freq[c]
      // or fre[c] is a multilple of i
      if(teste%i == 0 && i <= eq.back() && teste/i >= qt.size()) {
          qt.back() = teste/i;
          for(int j = (int)qt.size()-2; j >= 0; j--) {
            qt[j] = qt[j+1] -1;
            if(qt[j] <= 0) {
              pass = true;
              break;
            }
            pass |= freq[possible[j]]%qt[j];
          }
          
          if(!pass) {
            ans = solve();          
          }
       }
      pass = false;
      int ii = teste/i;
      if( teste%ii == 0 && ii != i && ii <= eq.back() && i >= qt.size()) {
          qt.back() = i;
          for(int j = (int)qt.size()-2; j >= 0; j--) {
            qt[j] = qt[j+1] -1;
            if(qt[j] <= 0) {
              pass = true;
              break;
            }
            pass |= freq[possible[j]]%qt[j];
          }
          if(!pass) {
            ans = solve();
          }
      }
    } 

    if(ans == "-1") out(ans);
    else
      out(ans, possible);
  }
}
