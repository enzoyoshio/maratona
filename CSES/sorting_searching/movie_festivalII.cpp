#include <bits/stdc++.h>

using namespace std;

#define OPEN 1
#define CLOSE -1

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> v(n);

    for(auto& [a, b]: v) cin >> b >> a;
    sort(v.begin(), v.end());

    multiset<int> times;
    int ans = 0;
    for(auto [finish, start]: v) {
      
      // se ninguem comecou a ver o filme
      if(times.empty()) {
        times.insert(finish);
        ans++;
      }else {
        auto p = times.upper_bound(start);

        if(p != times.begin()) {
          p--;
          ans++;
          times.erase(p);
          times.insert(finish);
        }else if(times.size() < k) {
          times.insert(finish);
          ans++;
        }

      }
    }

    cout << ans << endl;
}
