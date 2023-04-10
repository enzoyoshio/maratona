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

    set<int> disp;
    vector<int> ans(n);
    int cur = 0;
    for(auto [time, type, idx]: v) {
        
        // chegou um novo cara
        if(type == -1) {
            if(disp.empty()) {
		ans[idx] = ++cur;
	    }else
		ans[idx] = *disp.begin(), disp.erase(disp.begin());
        }

        if(type == 1) {
		disp.insert(ans[idx]);	
        }
    }

    cout << cur << endl;
    for(auto it: ans) 
        cout << it << ' ';
    cout << endl;
}
