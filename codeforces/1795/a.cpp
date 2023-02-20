#include <bits/stdc++.h>

#define int long long

using namespace std;

int solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int count = 0;
    for(int i = 1; i < n; i++) 
        if(s[i] == s[i-1]) count++;

    for(int i = 1; i < m; i++)
        if(t[i] == t[i-1]) count++;

    auto check = [](string& s, string& t) {
        for(int i = 1; i < s.size(); i++)
            if(s[i] == s[i-1]) return false;
        for(int i = 1; i < t.size(); i++)
            if(t[i] == t[i-1])
                return false;
        return true;
    };

    while(s.size() > 1) {
        if(check(s, t))
           return cout << "yes\n", 0;

        t.push_back(s.back());
        s.pop_back(); 
    }

    if(check(s, t)) 
        return cout << "yes\n", 0;

    while(t.size() > 1) {
        if(check(s, t)) 
            return cout << "yes\n", 0;

        s.push_back(t.back());
        t.pop_back();
    }

    if(check(s, t))
        return cout << "yes\n", 0;

    cout << "no\n";

    return 0;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}
