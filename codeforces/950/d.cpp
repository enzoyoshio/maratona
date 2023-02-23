#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    int q;
    cin >> n >> q;

    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if(x%2) {
            cout << (x+1)/2LL << endl;
            continue;
        } 

        int last = (n+1)/2LL;
        int aux = (n)/2;
        bool need = n%2;
        while((x)%2 == need) {
            last += (aux)/2; // this is right, dont change this line please
            
            x = (x+1)/ 2;
            
            need = !need; // I think this is also right, dont change this either
            aux = (aux+1)/ 2;  // this is also right
        }
        cout << last + (x+1)/2LL << endl;
    }
}
