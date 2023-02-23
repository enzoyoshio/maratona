#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MOD =  1'000'000'007;

int h, w, k;
vector<vector<vector<int>>> tb(20, vector<vector<int>>(110, vector<int>(20, -1)));

#define db(x) cout << "[ " << #x << " = " << x << " ]\n"

int fexp(int b, int e) {
    if(e == 0) return 1LL;

    int x = fexp(b, e/2);
    x = (x*x)%MOD;

    if(e%2) x = (x*b)%MOD;

    return x;
}

int dp(int stick, int height, int no) {

    if(stick < 1 || stick > w) return 0;
    if(height > h) {
        /*
        cout << "\ndbg\n";
        db(stick);
        db(height);
        db(no);
        */
 //       db( (w-1) * h - no);
 
        return (stick == k) * fexp(2, (w-1)*h - no);
    }

    auto& ans = tb[stick][height][no];

    if(~ans) return ans;

    int cur = 0;
    if(stick == 1) {
        cur = dp(stick+1, height+1, no+2);
        cur = (cur + dp(stick, height+1, no+ (w == 1 ? 0 : 1) ))%MOD;
    }else if(stick == w) {
        cur = dp(stick-1, height+1, no+2);
        cur = (cur + dp(stick, height+1, no+ (w == 1 ? 0 : 1)))%MOD;
    }else {
        cur = dp(stick, height+1, no+2);
        cur = (cur + dp(stick+1, height+1, no+2+ (stick+1 == w? 0: 1)))%MOD;
        cur = (cur + dp(stick-1, height+1, no+2+ (stick-1 == 1? 0: 1)))%MOD;
    }

    //return cur;
    return ans = cur;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> h >> w >> k;
    cout << dp(1, 1, 0) << endl;
}
