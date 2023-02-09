#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    string s;
    cin >> s;
    int base = 1, ans = 0;

    while(!s.empty()) {
        int cur = s.back()-'A'+1; s.pop_back();

        ans += base*cur;
        base *= 26;
    }

    cout << ans << endl;
}
