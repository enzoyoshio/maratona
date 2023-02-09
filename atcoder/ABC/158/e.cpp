#include <bits/stdc++.h>

#define int long long

using namespace std;

int fexp(int b, int e, int p) {
    if(e == 0) return 1LL;

    int x = fexp(b, e/2, p);
    x = (x*x)%p;

    if(e%2) x = (x*b)%p;

    return x;
}

int inv(int n, int p) {
    return fexp(n, p-2, p);
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, p; 
    string s;
    cin >> n >> p >> s;
    reverse(s.begin(), s.end());

    vector<int> psum(n);
    int base = 1;
    int ans = 0;
    map<int,int> lembra;

    for(int i = 0; i < n; i++) {
        psum[i] = (base * (s[i]-'0'))%p;
        base = (base*10)%p;
        cout << "calculado " << psum[i] << endl;
        if(i) psum[i] = (psum[i] + psum[i-1])%p;
        cout << "soma " << psum[i] << endl;
        ans += lembra[psum[i]];
        lembra[psum[i]]++;    
    }
    cout << s << endl;
    for(auto el: psum) cout << el << ' ';
    cout << endl;

    int brute = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(i && ( (psum[j]-psum[i-1] + p)%p * inv(fexp(10, i, p), p) ) %p == 0) {
                cout << "\n\noi\n";
                cout << "id = " << j <<  ' ' << i << '\n';
                cout << "psum j = " << psum[j] << " psum i - 1 = " << psum[i-1] << endl;
                for(int k = j; k >= i; k--) 
                    cout << s[k];
                cout << endl;
                brute++;
            }else if((psum[j] * inv(fexp(10, j, p), p))%p == 0) {
                cout << "\n\noi\n";
                cout << "id = " << j << endl;
                cout << "psum j = " << psum[j] << endl;
                for(int k = j; k >= i; k--) 
                    cout << s[k];
                cout << endl;
                brute++;
            }
        }
    }

    cout << "brute = " << brute << endl;
    cout << ans << endl;



}
