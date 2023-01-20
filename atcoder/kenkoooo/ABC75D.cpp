#include <bits/stdc++.h>

#define int long long

using namespace std;

int n, k;
const int oo = 4e18;

int t(vector<int> xs, vector<int> ys, int i, int j) {
    vector<int> inside;
    int n = xs.size();
    
    if(i > j) swap(i, j);

    for(int idx = 0; idx < n; idx++) {
        if(i <= xs[idx] && xs[idx] <= j) inside.push_back(ys[idx]);
    } 

    sort(inside.begin(), inside.end());

    if(inside.size() < k) return oo;

    int width = abs(i-j);
    int length = oo;
    for(int idx = 0; idx+k-1 < inside.size(); idx++) {
        length = min(length, abs(inside[idx]-inside[idx+k-1]));
    }

    return width*length;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> k;
    vector<int> xs(n), ys(n);
    for(int i = 0; i < n; i++)
        cin >> xs[i] >> ys[i];

    int ans = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int best = min(t(xs, ys, xs[i], xs[j]), t(ys, xs, ys[i], ys[j]));
            if(ans == -1)  ans = best;
            else ans = min(ans, best); 
        }
    }

    cout << ans << endl;
}
