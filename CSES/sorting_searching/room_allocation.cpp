#include <bits/stdc++.h>

using namespace std;

using tiii = tuple<int,int,int>;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<tiii> v;
    for(int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        v.emplace_back(l, -1, i);
        v.emplace_back(r, 1, i);
    }

    sort(v.begin(), v.end());

    vector<int> ans(n);
    int cur = 0;
    for(auto [time, type, idx]: v) {
        
        // chegou um novo cara
        if(type == -1) {
            ans[idx] = ++cur;
        }

        if(type == 1) {
            cur--;
        }
    }

    cout << ans.size() << endl;
    for(auto it: ans) 
        cout << it << ' ';
    cout << endl;
}
