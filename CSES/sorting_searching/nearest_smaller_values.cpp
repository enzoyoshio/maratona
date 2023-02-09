#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n), ans(n, 0);
    for(auto& it: v) 
        cin >> it;

    stack<pair<int,int>> st;

    for(int i = n-1; i >= 0; i--) {
        while(st.size() && st.top().first > v[i]) {
            ans[st.top().second] = i+1;
            st.pop();
        }

        st.emplace(v[i], i);
    }

    for(auto it: ans) 
        cout << it << ' ';
    cout << endl;
}
