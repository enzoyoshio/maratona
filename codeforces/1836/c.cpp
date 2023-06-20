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

void print(int a, int b, int c) {
  cout << a << " + " << b << " = " << c << '\n';
}

int digits(int num) {
  int c = 0;
  while(num) c++, num /= 10;
  return c;
}
auto main() -> signed {
  fastio;

  V<int> fexp(10);
  fexp[0] = 1;
  for(int i = 1; i < fexp.size(); i++) fexp[i] = fexp[i-1]*10;

  V<V<V<V<iii>>>> save(4, V<V<V<iii>>>(4, V<V<iii>>(4)));

  for(int i = 1; i < 1000; i++) {
    for(int j = 1; j < 1000; j++) {
      if(to_string(i+j).size() > 3) continue;
      save[digits(i)][digits(j)][digits(i+j)].eb(iii{i, j, i+j});
    }
  }

  int t; in(t); while(t--) {
    int a, b, c, k; in(a, b, c, k);
    
    if(max(a, b) + 1 < c || c < min(a, b)) {
      out(-1);
      continue;
    }

    if(a<= 3 && b<= 3 && c<= 3) {
      k--;
      if(save[a][b][c].size() > k) {
        auto [aa, bb, cc] = save[a][b][c][k];
        print(aa, bb, cc);
      }
      else out(-1);
      continue;
    }

    int a1 = fexp[a-1];
    int a2 = fexp[a]-1;
    bool good = false;
    for(int i = a1; i <= a2 && !good; i++) {
      if(k < 0) break;
      int l = fexp[b-1], r = fexp[b]-1, ans = l-1;

      int first = digits(i+l);
      // acha o numero mais alto tal que nao estoure;
      while(l <= r) {
        int mid = (l+r)/2;

        if(digits(i + mid) == first) ans = mid, l = mid+1;
        else r = mid-1; 
      }
      /*
      db(var(i));
      db(var(ans));
      db(var(k));
      */

      if(first == c) {
        // k ta aqui
        if(k <= ans-fexp[b-1]+1) {
          print(i, fexp[b-1] + k-1, i+fexp[b-1]+k-1);
          good = true;
        }else {
          k -= ans-fexp[b-1]+1;
        }
      }else {

        if(k <= fexp[b]-1-ans) {
          print(i, ans+k, i+ans+k);
          good = true;
        }else {
          k -= fexp[b]-ans-1;
        }
      }
    }

    if(!good) out(-1);
  }
}
