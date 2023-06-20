#include <bits/stdc++.h>
using namespace std;
//alias comp='g++ -std=c++17 -g -O2 -Wall -Wconversion -Wshadow -fsanitize=address,undefined -fno-sanitize-recover -ggdb -o out'

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define endl "\n"
#define input(x) for (auto &it : x) cin >> it
#define pb push_back
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define TETO(a, b) ((a) + (b-1))/(b)
#define dbg(msg, x) cout << msg << " = " << x << endl
#define print(x,y) for (auto &it : x) cout << it

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef priority_queue<int, vector<int>, greater<int>> pqi;

const ll MOD = 1e9+7;
const int MAX = 1e4+5;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

/* Chopper Supremacy :3 */

int32_t main(){ sws;
    int n; cin>>n;
    vector<int> v(n); input(v);
    vector<int> erro(n);
    for(auto& it: erro) cin >> it;
    sort(all(v));
    sort(all(erro));

    /*
    if(erro.back() > v.back() - v[0] + 1) {
        bool can = v[0] - erro[0] > 0;
        for(int i = 0; i < n; i++) {
            if(v[i] - erro[i] != v[0] - erro[0]) can = false;
        }

        if(can)
            ans.pb(v[0]-erro[0]);
        can = v[0] + erro.back() <= 1000000000;
        for(int i = 0; i < n; i++) {
            if(v[i] + erro[n-i-1] != v[0] + erro.back()) can = false;
        }
        if(can)
            ans.pb(v[0] + erro.back());
        
        if(ans.empty()) assert(false);
        else {
            sort(all(ans));
            for(auto it: ans) cout << it << endl;
        }
        return 0;
    }
    */


    set<int> ans;
    int x = v[0] + erro.back();
    vector<int> poss;
    if(x <= 1000000000) {
      poss.pb(erro.back());
      for(int i = 1; i < n; i++) {
          poss.pb(abs(v[i]-x));
      }
      sort(all(poss));
      if(erro == poss) {
        ans.insert(x);
      }
    }

    x = v.back() - erro.back();
    if(x > 0) {
      poss = {erro.back()};
      for(int i = 0; i+1 < n; i++) {
          poss.pb(abs(v[i]-x));
      }
      sort(all(poss));
      if(erro == poss)
        ans.insert(x);
    }
    
    if(ans.empty()) assert(false);
    for(auto it: ans) cout << it << '\n';
}
