#include <bits/stdc++.h> 

#define int long long 

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, z, w;
    cin >> n >> z >> w;
    vector<int> v(n);
    for(int i = 0; i < n; i++) 
        cin >> v[i];

    if(n == 1) {
        cout << abs(w-v[0]);
        return 0;
    }

    cout << max(abs(v[n-2]-v.back()), abs(v.back()-w));
}
