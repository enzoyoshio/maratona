#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MAXN = 35;

signed main() {
    int n; cin >> n;

    if(n == 0) return cout << 0 << endl, 0;

    bitset<MAXN> original(n), res(0);

    for(int i = 0; i < MAXN; i++) {
        // se na base 2 eu preciso desse numero
        if(original[i] == 1) {
            // se for um expoente impar
            if(i%2) {
                if(res[i])  res[i] = 0;
                else        res[i] = res[i+1] = 1;
            }else {
                if(res[i])  res[i+1] = res[i+2] = 1, res[i] = 0;
                else        res[i] = 1;
            }
        }
    }
    string ans = res.to_string();
    reverse(ans.begin(), ans.end());
    while(ans.size() && ans.back() == '0') ans.pop_back();

    reverse(ans.begin(), ans.end());

    cout << ans << endl;
    
}

// 1    -> 1 -> 1 * (-2)**0 -> 1
// 0    -> 0
// 2    -> 1 * (-2)**2 + 1 * (-2)**1 + 0 * (-2)**0 -> 110
// 3    -> 111 -> (2)   11
// 4    -> 100 ->       100
// 5    -> 101 ->       101
// 6    -> 11010        110
// 7    -> 11011        111
// 8    -> 11000        1000
// 9    -> 11001        1001
// 10   -> 11110        1010
// 11   -> 11111        1011
