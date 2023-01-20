#include <bits/stdc++.h>

#define int long long

using namespace std;

#define START -1
#define END 1

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, c;
    cin >> n >> c;
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++) {
        int s, t, channel;
        cin >> s >> t >> channel;
        v.emplace_back(s, START);
        v.emplace_back(t, END);
    }

    sort(v.begin(), v.end());
    int ans = 0;
    int cur = 0;

    for(auto [time, op]: v) {
    
        if(op == START) {
            cur++;
        }

        if(op == END) 
            cur--;

        ans = max(ans, cur);

    }

    cout << min(ans, c) << endl;
}
