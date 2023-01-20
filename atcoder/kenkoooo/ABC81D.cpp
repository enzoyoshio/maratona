#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> pos(vector<int>& v) {
    vector<pair<int,int>> ret;
    int n = v.size();
    
    for(int i = 1; i < n; i++) {
        if(v[i] < v[i-1]) ret.emplace_back(i-1, i), v[i] += v[i-1];
    }
    return ret;
}

vector<pair<int,int>> neg(vector<int>& v) {
    vector<pair<int,int>> ret;
    int n = v.size();

    for(int i = n-2; i >= 0; i--) 
        if(v[i] > v[i+1])
            ret.emplace_back(i+1, i), v[i] += v[i+1];
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& it: v) cin >> it;

    auto mx = max_element(v.begin(), v.end());
    auto mn = min_element(v.begin(), v.end());

    vector<pair<int,int>> ans;
    vector<pair<int,int>> res;
    if(abs(*mx) > abs(*mn)) {
        int idx = mx-v.begin();
        for(int i = 0; i < n; i++) {
            if(i == idx) continue;
            ans.emplace_back(idx, i);
            v[i] += v[idx];
        }
        res = pos(v);
    }else {
        int idx = mn-v.begin();
        for(int i = 0; i < n; i++) {
            if(i == idx) continue;
            ans.emplace_back(idx, i);
            v[i] += v[idx];
        }
        res = neg(v);
    }
    ans.insert(ans.end(), res.begin(), res.end());

    cout << ans.size() << endl;
    for(auto [a, b]: ans) cout << a+1 << ' ' << b+1 << '\n';
}
