#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    string s;
    cin >> s;
    int n = (int)s.size();

    vector<int> zeros(n, 0), uns(n, 0);
    for(int i = 0; i < n; i++) {
        zeros[i] = s[i] == '0';
        uns[i] = s[i] == '1';
        if(i) zeros[i] += zeros[i-1], uns[i] += uns[i-1];
    }

    for(int i = 0; i < n; i++)
        if(uns[i] > zeros[i]) 
            return cout << -1 << endl, 0;

    for(int i = n-1; i >= 0; i--) 
        if(uns.back() - (i ? uns[i-1] : 0) > zeros.back() - (i ? zeros[i-1] : 0)) 
            return cout << -1 << endl, 0;

    vector<vector<int>> ans(zeros.back(), vector<int>());
    
    int idx = 0;
    for(int i = 0; i < n; i++)
        if(s[i] == '0')
            ans[idx++].push_back(i);

    vector<int> need0;
    idx = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            if(idx >= (int)ans.size()) 
                return cout << -1 << endl, 0;
            need0.push_back(idx);
            ans[idx++].push_back(i);
        }
    }

    vector<int> nx((int)ans.size(), -1);
    int res = (int)ans.size();
    idx = 0;
    for(int i = 0; i < ans.size(); i++) {
        if(idx < need0.size() && ans[i][0] > ans[need0[idx]].back()) {
            nx[need0[idx]] = i;
            idx++;
            res--;
        }
    }

    if(idx < need0.size())
        return cout << -1 << endl, 0;

    vector<int> vis((int)ans.size(), 0);
    cout << res << endl;
    for(int i = 0; i < (int)ans.size(); i++) {
        if(vis[i]) continue;

        int tam = 0; 
        int cur = i;
        while(cur != -1) {
            vis[cur] = 1;
            tam += ans[cur].size();
            cur = nx[cur];
        }
        cout << tam << ' ' ;
        cur = i;
        while(cur != -1) {
            for(auto el: ans[cur])
                cout << el + 1 << ' ';
            cur = nx[cur];
        }
        cout << endl;
    }
}
