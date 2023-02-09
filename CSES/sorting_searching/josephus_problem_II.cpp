#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    vector<int> kth_next(n), next(n), prev(n);
    int cur = 0;

    for(int i = 0; i < n; i++) {
        next[i] = (i+1)%n;
        kth_next[i] = (i+k)%n;
        prev[i] = (i-1+n)%n;
    }

    while(kth_next[cur] != cur) {
        cout << kth_next[cur] + 1 << ' ';
        
        int p = prev[kth_next[cur]];

        next[p] = next[next[p]];
        kth_next[p] = kth_next[kth_next[cur]];
        prev[next[kth_next[cur]]] = p;
        kth_next[cur] = next[kth_next[cur]];
        cur = next[kth_next[cur]];
    }
    cout << cur+1 << endl;
}
