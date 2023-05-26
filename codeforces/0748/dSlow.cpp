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

using ull = unsigned long long;

ull mix(ull o){
    o+=0x9e3779b97f4a7c15;
    o=(o^(o>>30))*0xbf58476d1ce4e5b9;
    o=(o^(o>>27))*0x94d049bb133111eb;
    return o^(o>>31);
    //Those constants supposedly are chosen to give this function better pseudo-random properties, but on any on-site contest, when one can't have team reference document/doesn't want to waste time searching it for implementation typing arbitrary large odd numbers by hand should be good enough
}

const int oo = 1e7;

ull hashh(string const& s) {
  ull h = 0;
  for(auto ch: s)
    h = mix(h ^ mix(ch));
  return h;
}
int add(int a, int b, int mod) {
  return (a+b)%mod;
}
 
int sub(int a, int b, int mod) {
  return ((a-b)%mod + mod)%mod;
}
 
int mul(int a, int b, int mod) {
  return (a*b)%mod;
}
 
int fexp(int b, int e, int mod) {
  if(e == 0) return 1;
 
  int x = fexp(b, e/2, mod);
  x = mul(x, x, mod);
 
  if(e%2) x = mul(x, b, mod);
 
  return x;
}
 
struct Hash {
  vector<int> mods = {998244853, 998244353, 998244853, 1000015187, 1000027957, 1000041323}; 
  int p = 7, n;
  vector<vector<int>> h, powers, invs;
 
  Hash(string& s) {
    n = s.size();
    h.assign((mods.size()), vector<int>(n));
    powers = invs = h;
    build(s);
  }
 
  void build(string& s) {
    for(int mod = 0; mod < mods.size(); mod++) { 
      powers[mod][0] = 1;
      for(int i = 1; i < n; i++) {
        powers[mod][i] = mul(powers[mod][i-1], p, mods[mod]);
      }
      invs[mod].back() = fexp(powers[mod].back(), mods[mod]-2, mods[mod]);
      for(int i = n-2; i >= 0; i--) {
        invs[mod][i] = mul(invs[mod][i+1], p, mods[mod]);
      }
 
      for(int i = 0; i < n; i++) {
        h[mod][i] = mul(s[i], powers[mod][i], mods[mod]);
 
        if(i)
          h[mod][i] = add(h[mod][i], h[mod][i-1], mods[mod]);
      }
    }
  }
 
  vector<int> query(int l, int r) {
    vector<int> ans(mods.size());
    for(int mod = 0; mod < mods.size(); mod++) {
      if(!l) {
        ans[mod] = h[mod][r];
        continue;
      }
 
      int su = mul(h[mod][l-1], invs[mod][l-1], mods[mod]);
      ans[mod] = mul(sub(h[mod][r], h[mod][l-1], mods[mod]), invs[mod][l], mods[mod]); 
    }
    return ans;
  }
 
  vector<int> merge(int idx, char c) {
    vector<int> ans(mods.size());
    if(idx == 0) {
      auto suf = query(1, n-1);
 
      for(int mod = 0; mod < mods.size(); mod++) {
        ans[mod] = mul(c, powers[mod][0], mods[mod]);
        int resto = mul(suf[mod], powers[mod][1], mods[mod]);
        ans[mod] = add(ans[mod], resto, mods[mod]);
      }
       
    }else if(idx == n-1) {
      auto pref = query(0, n-2);
 
      for(int mod = 0; mod < mods.size(); mod++) {
        ans[mod] = mul(c, powers[mod][n-1], mods[mod]);
        ans[mod] = add(ans[mod], pref[mod], mods[mod]);
      }
    }else {
 
      auto pref = query(0, idx-1);
      auto suf = query(idx+1, n-1);
 
      for(int mod = 0; mod < mods.size(); mod++) {
        ans[mod] = mul(c, powers[mod][idx], mods[mod]);
        ans[mod] = add(ans[mod], pref[mod], mods[mod]);
        ans[mod] = add(ans[mod], mul(suf[mod], powers[mod][idx+1], mods[mod]), mods[mod]);
      }
    }
    return ans;
  }
};
 
auto main() -> signed {
  fastio;

  int n, m;
  cin >> n >> m;

  map<pair<string, string>,vector<int>> ans;

  for(int i = 0; i < n; i++) {
    string s; int val;
    cin >> s >> val;
    string t = s;
    reverse(begin(t), end(t));
    /*
    cerr << "\n\n--------------- db ----------------\n";
    db(var(s));
    db(var(normal));
    db(var(s));
    db(var(reversed));
    */

    ans[{s, t}].emplace_back(val);
  }

  int res = 0, eq = 0, cpal = 0;
  pair<int,int> unik(-oo,-oo);
  for(auto [a, b]: ans) {

    // se a string for um palindromo
    if(a.first == a.second) {
      sort(begin(b), end(b));
      while(b.size() > 1) {
        auto t1 = b.back(); b.pop_back();
        auto t2 = b.back(); b.pop_back();
        if(t1 + t2 <= 0) {
          b.push_back(t2);
          b.push_back(t1);
          break;
        }
        /*
        db(var(a.first));
        db(var(t1));
        db(var(t2));
        */
        eq += t1 + t2; 
        if(t2 < 0)
          unik = max(unik, {t1, t2});
      }
      if(b.size() && b.back() > 0) cpal = max(cpal, b.back()); 
      continue;
    }

    if(ans.find({a.second, a.first}) == ans.end()) continue;

    auto b2 = ans[{a.second, a.first}];
    sort(begin(b), end(b));
    sort(begin(b2), end(b2));
    while(b.size() && b2.size()) {
      if(b.back() + b2.back() > 0) {
        res += b.back() + b2.back();
        /*
        db(var(a.first));
        db(var(a.second));
        db(var(b.back()));
        db(var(b2.back()));
        */
        b.pop_back();
        b2.pop_back();
      }else {
        break;
      }
    }
  }

  if(!cpal && unik.first != -oo)
    eq -= unik.second;
  else if(unik.first != -oo && -unik.second > cpal) {
    eq -= unik.second;
    cpal = 0;
  }

  cout << res/2 + eq + cpal << endl;
}

// aa bb ab ba
// ab ba
// ba ab
