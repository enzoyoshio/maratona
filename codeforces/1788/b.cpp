#include <bits/stdc++.h>

#define int long long

using namespace std;

int teste(int n) {
    int sum = 0;
    while(n) {
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int teste(string s) {
    int sum = 0;
    for(auto ch: s) sum += ch-'0';
    return sum;
}

int solve() {
    int n;
    cin >> n;
    int x = 0, y = 0;
    string s = to_string(n), t = "", u = "";

    for(auto ch: s) {
        int num = ch-'0';
        t += num/2 + '0';
        u += (num+1)/2  + '0'; 
    }

    for(int i = 0; i < (int)s.size(); i++) {
        if(abs(teste(t) - teste(u)) > 1) {
            swap(t[i], u[i]);
        }
    } 

    cout << stoll(t) << ' ' << stoll(u) << endl;
    return 0; 
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t=1;
    cin >> t;
    while(t--) 
        solve();
}
