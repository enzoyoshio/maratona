#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> next(n), prev(n);
    for(int i = 0; i < n; i++) {
        next[i] = (i+1)%n;
        prev[i] = (i-1+n)%n;
    }

    int cur = 0;

    while(next[cur] != cur) {
        cout << next[cur]+1 << ' ';
        //prev[next[next[cur]]] = cur;
        next[cur] = next[next[cur]];
        cur = next[cur];
    }
    cout << cur+1 << endl;
}
