#include <bits/stdc++.h>

using namespace std;

#define OPEN 1
#define CLOSE -1

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> v;
    int ans = n;

    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.emplace_back(a, OPEN);
        v.emplace_back(b, CLOSE);
    }

    sort(v.begin(), v.end());

    int cur = 0;
    for(auto [time, type]: v) {

        if(type == OPEN) {
            cur++;
        }

        if(type == CLOSE) {
            cur--;
        }
        if(cur > k) ans--;
    }

    cout << ans << endl;
}
