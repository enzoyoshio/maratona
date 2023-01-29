#include <bits/stdc++.h>

using namespace std;

#define RED 0
#define BLUE 1

using tiii = tuple<int,int,int>;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> grid(300, vector<int>(300, -1));
    vector<tuple<int,int,int>> v(2*n);

    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v[i] = {a, b, RED};
        grid[b][a] = RED;
    }
    for(int i = n; i < 2*n; i++) {
        int a, b; cin >> a >> b;
        v[i] = {a, b, BLUE};
        grid[b][a] = BLUE;
    }

    int qtR = 0, ans = 0;
    /*
    for(int i = 0; i < 300; i++) {
        for(int j = 0; j < 300; j++) {
            if(grid[i][j] == BLUE) {
                bool find = false;
                for(int k = i-1; k >= 0; k--) {
                }
                for(int k = 0; !find && k < i; k++) {
                    for(int l = 0; !find && l < j; l++) {
                        if(grid[k][l] == RED) {
                            grid[k][l] = -1, ans++, find = true;
                            ////cout << "encontrei no " << i << ' ' << j << endl;
                            //cout << "vermelho no " << k << ' ' << l << endl;
                        }
                    }
                }            
            }
        }
    }
    cout << ans << endl;
    return 0;
    */

    sort(v.begin(), v.end(), [](tiii a, tiii b) {
        auto [ax, ay, ap] = a;
        auto [bx, by, bp] = b;

        return (ax < bx) || (ax == bx && ay < by);
            });

    set<int> ys;
    for(auto [x, y, type]: v) {
        if(type == RED) ys.insert(y);
        else {
            auto val = ys.lower_bound(y);

            if(val == ys.begin()) continue;

            val--;
            ys.erase(val);
            ans++;
        }
    }

    cout << ans << endl;
}
