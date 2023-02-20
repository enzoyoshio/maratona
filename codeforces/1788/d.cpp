#include <bits/stdc++.h>

#define int long long

using namespace std;

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"

const int MOD = 1e9+7;
const int MAXN = 3030;
vector<int> fast(MAXN);

int solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& it: v) 
       cin >> it;

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int dist = abs(v[j]-v[i]);
            
            int li = 0, ri = i, ansi = 0;
            while(li <= ri) {
                int mid = (li+ri) >> 1;

                if(abs(v[i] - v[mid]) > dist) ansi = mid+1, li = mid+1;
                else ri = mid-1;
            }

            int lj = j, rj = n-1, ansj = n;
            while(lj <= rj) {
                int mid = (lj + rj) >> 1;

                if(abs(v[j]-v[mid]) >= dist) ansj = mid, rj = mid-1;
                else lj = mid+1;
            }

//            cout << "\n\ndbg\n";
//            db(i);
//            db(j);
//            db(ansi);
//            db(ansj);
//            db(n-ansj);
//            db(fast[ansi]);
//            db(fast[n-ansj]);
            
            ans = (ans + (fast[ansi] * fast[n-ansj])%MOD)%MOD;
        }
    }
    cout << ans << endl;
    return 0;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    fast[0] = 1;
    for(int i = 1; i < MAXN; i++)
        fast[i] = (fast[i-1] * 2)%MOD;

    int t=1;
    while(t--) 
        solve();
}
