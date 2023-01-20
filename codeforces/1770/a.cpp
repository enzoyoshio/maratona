#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t; 
    while(t--) {
        int n, m;
        cin >> n >> m;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; i++) {
            int a; cin >> a; pq.push(a);
        }    

        for(int i = 0; i < m; i++) {
            int a; cin >> a;
            pq.pop(); pq.push(a);
        }

        int sum = 0;
        while(pq.size()) sum += pq.top(), pq.pop();
        cout << sum << endl;
            
    }
}
