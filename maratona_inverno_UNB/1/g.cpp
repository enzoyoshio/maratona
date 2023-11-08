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
using ll = long long;

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

const vector<int> mods = {
        1000015187//, 1000027957
};
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count()); // random number
const ll base = uniform_int_distribution<int>(356, mods[0]-1)(rng); // alphabet < base < mod1

struct hash_string{
    string s;
    ll n;
    vector<vector<int>> hashes, power, inv;

    hash_string(): n(0){}
    hash_string(string _s)
        : n(_s.size()), s(_s),
        hashes(mods.size(),vector<int>(n)),
        power(mods.size(),vector<int>(n)),
        inv(mods.size(),vector<int>(n))
        {
        for(int i=0; i<mods.size(); i++){
            power[i][0] = 1, inv[i][0] = 1;
            for(int j=1; j<n; j++){
                power[i][j] = mul(power[i][j-1], base, mods[i]);
            }
            inv[i][n-1] = fexp(power[i][n-1], mods[i]-2, mods[i]);
            for(int j=n-2; j>=0; j--){
                inv[i][j] = mul(inv[i][j+1], base, mods[i]);
            }
            hashes[i][0] = s[0];
            for(int j=1; j<n; j++){
                hashes[i][j] = add(hashes[i][j-1], mul(power[i][j], (int)(s[j]), mods[i]), mods[i]);
            }
        }
    }
    // return vector of hashes [l, r]
    int query(int l, int r){
 //       vector<int> get_hashes;
        for(int i=0; i<mods.size(); i++){
            // hashes[r] - hashes[l-1]
            int res = hashes[i][r];
            if(l > 0) res = sub(res, hashes[i][l-1], mods[i]);
            res = mul(res, inv[i][l], mods[i]);
            return res;
  //          get_hashes.pb(res);
        }
//        return get_hashes;
    }

    vector<int> update(int idx, int c){
        vector<int> get_hashes;
        for(int i=0; i<mods.size(); i++){
            int h = hashes[i][n-1];
            int m = mul((int)s[idx], power[i][idx], mods[i]);
            h = sub(h, m, mods[i]);
            m = mul(c, power[i][idx], mods[i]);
            h = add(h, m, mods[i]);
            get_hashes.pb(h);
        }
        return get_hashes;
    }
};

auto main() -> signed {
  fastio;

  int n;
  string s;
  in(n, s);
  string novo = "#";
  for(auto ch: s) {
    novo.push_back(ch);
    novo.push_back('#');
  }
  string t = novo;
  reverse(begin(t), end(t));

  hash_string hs(novo), hr(t);
  
  vector<int> ans(sz(novo));
  for(int i = 0; i < sz(novo); i++) {
    
    int bl = 0, br = sz(novo), bans = 0;

    while(bl <= br) {
      int bm = (bl+br)/2;

      int tol = i-bm;
      int tor = i+bm;

      if(tol < 0 || tor >= novo.size() || hs.query(tol, tor) != hr.query(sz(novo) - tor-1, sz(novo) - tol-1)) br = bm-1;
      else bl = bm+1, bans = bm;
    }

    // cheguei no maior palindromo possivel
    // [i-bans, i+bans] = longest palyndrom valid
    // add bans+1 to answer;

    // proxima resposta
    int wrong_left = i-bans-2, wrong_right = i+bans+2, b2ans = 0;
    bl = 0, br = sz(novo);

    if(i-bans-1 < 0 || i+bans+1 >= sz(novo)) {
      ans[i] = bans+1;
      continue;
    }
    if(novo[wrong_left] != novo[wrong_right]) {
      ans[i] = bans+1;
      continue;
    }

    while(bl <= br) {
      int bm = (bl + br)/2;

      int tol = wrong_left - bm;
      int tor = wrong_right + bm;

      // tol -> wrong_left == wrong_right -> tor
      if(tol < 0 || tor >= sz(novo) || hs.query(tol, wrong_left) != hr.query(sz(novo) - tor-1, sz(novo)-wrong_right-1)) br = bm-1;
      else bl = bm+1, b2ans = bm;
    }

    ans[i] = bans+2 + b2ans+1;
  }

  int res = 0;
  for(int i = 0; i < sz(novo); i++) {
    if(i%2) res += ans[i]/2;
    else res += (ans[i]-1)/2;
  }
  out(res);
}
