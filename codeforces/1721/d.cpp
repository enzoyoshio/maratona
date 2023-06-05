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

// the idea is right, but I dont know how to implement it
// in a recursion way, going to code it iteratively just like quirino
int make(V<int>& a, V<int>& b, int id) {
  int n = a.size();

  if(id < 0) return 0;

  int countA = 0;
  int countB = 0;
  for(int i = 0; i < n; i++) {
    if( ((a[i] >> id) & 1) != 0) countA++;
    if( ((b[i] >> id) & 1) != 0) countB++;
  }

  int left = -1, right = -1;
  // o xor deles depois de dar 1, vai ser 1
  if(countA + countB == (int)a.size()) {
    V<int> a1, a0, b1, b0;

    for(int i = 0; i < n; i++) {
      if( ((a[i] >> id) & 1) != 0) a1.eb(a[i]);
      else a0.eb(a[i]);

      if( ((b[i] >> id) & 1) != 0) b1.eb(b[i]);
      else b0.eb(b[i]);
    }

    int ans = 1LL << id;

//    V<int> prevs;
    for(int i = 0; i < id; i++) {
//      prevs.eb((1LL << id) | (make(a1, b0, i) & make(a0, b1, i)));
//      ans = max(ans, prevs.back());
      ans = max(ans, (1LL << id) | (make(a1, b0, i) & make(a0, b1, i)));
    }

    /*
    cerr << "\n\n--------------- db -----------\n";
    db(var(a));
    db(var(b));
    db(var(id));
    db(var(a1));
    db(var(a0));
    db(var(b1));
    db(var(b0));
    db(var(countA));
    db(var(countB));
    db(var(ans));
    db(var(prevs));
    */

    return ans;
  }
 
  /*
    cerr << "\n\n--------------- db failed -----------\n";
    db(var(a));
    db(var(b));
    db(var(id));
    db(var(left));
    db(var(right));
    db(var(countA));
    db(var(countB));
    */


  return make(a, b, id-1);
}

template<class T, class X>
using vp = V<pair<T, X>>; 

auto main() -> signed {
  fastio;

  int t; in(t); while(t--) {
    int n; in(n);

    V<int> a(n), b(n);
    in(a, b);
    vp<V<int>, V<int>> half{{a, b}}; 

    int ans = 0;
    for(int bit = 31; bit >= 0; bit--) {

      bool possible = true;
      for(auto [va, vb]: half) {

        int qta = 0, qtb = 0;
        for(auto it: va)
          if((it >> bit) &1) qta++;
        for(auto it: vb)
          if((it >> bit) &1) qtb++;

        if(qta + qtb != sz(va)) {
          possible = false;
          break;
        }
      }
      if(!possible) continue;

      ans |= 1 << bit;
      vp<V<int>, V<int>> novo;
      for(auto [va, vb]: half) {
        
        pair<V<int>, V<int>> a1b0, a0b1;

        for(auto it: va) {
          if((it >> bit) & 1) a1b0.first.eb(it);
          else a0b1.first.eb(it);
        }

        for(auto it: vb) {
          if((it >> bit) & 1) a0b1.second.eb(it);
          else a1b0.second.eb(it);
        }

        if(a0b1.first.size()) novo.eb(a0b1);
        if(a1b0.first.size()) novo.eb(a1b0);
      }
      swap(half, novo);
    }

    out(ans);
  }
}
