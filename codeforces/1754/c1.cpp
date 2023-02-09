#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5;
int n;
vector<int> v(MAXN);

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t; while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int um = 0, neg = 0;
        for(int i = 0; i < n; i++) {
            if(v[i] == 1) um++;
            else if(v[i] == -1) neg++;
        }
    
        if(um == neg) {
            cout << n << endl;
            for(int i = 1; i <= n; i++) {
                cout << i << ' ' << i << endl;
            }
            continue;
        }

        if(um%2 != neg%2) {
            cout << -1 << endl;
            continue;
        }

        vector<pair<int,int>> ans;
        for(int i = 1; i < n; i++) {
            if(v[i] == -1 && neg > um) {
                ans.emplace_back(i, i+1);
                neg--, um++;
                i++;
            }
            if(v[i] == 1 && um > neg) {
                ans.emplace_back(i, i+1);
                um--, neg++;
                i++;
            }
        }

        if(um != neg) {
            cout << -1 << endl;
            continue;
        }
        vector<pair<int, int>> res;
        for(int i = 1; i < ans[0].first; i++)
            res.emplace_back(i, i);

        for(int i = 0; i < (int)ans.size(); i++) {
            if(i && abs(ans[i].first - ans[i-1].second) > 1) {
                for(int j = ans[i-1].second + 1; j < ans[i].first;j++)
                    res.emplace_back(j, j);
            }
            res.push_back(ans[i]);
        }

        for(int i = ans.back().second+1; i <= n; i++)
            res.emplace_back(i, i);

        cout << res.size() << endl;
        for(auto [a, b]: res) cout << a << ' ' << b << endl;
    }
}
