#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, ans = 0, all;
    cin >> n;
    all = n;
    while(n--) {
        string s;
        cin >> s;
        for(int i = 0; i < s.size()-1; i++) {
            if(s[i] == 'C' && s[i+1] == 'D') {
                ans++;
                break;
            }
        }
    }

    cout << all - ans << endl;
}
