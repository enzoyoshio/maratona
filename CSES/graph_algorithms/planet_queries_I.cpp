#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<int> next(n);
    for(auto& it: next) 
        cin >> it, it--;

    int logSize = 1 + (int)log2((int)1e9+1);
    vector<vector<int>> jumps(logSize, vector<int>(n));

    for(int i = 0; i < n; i++) {
        jumps[0][i] = next[i];
    }

    for(int jump = 1; jump < logSize; jump++) {
        for(int i = 0; i < n; i++) {
            jumps[jump][i] = jumps[jump-1][jumps[jump-1][i]];
        }
    }

    while(q--) {
        int a, b; cin >> a >> b; a--;
        
        for(int i = 0; i < logSize; i++) {
            if( (b&(1 << i)) != 0) {
                a = jumps[i][a];
            }
        }
        cout << a+1 << endl;
    }
}
