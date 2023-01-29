#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int m; cin >> m;

    cout << n << ' ' << m << endl;
    for(int i = 0; i < n; i++) {
        for(int j= 0; j < m; j++)
            cout << 1;
        cout << endl;
    }
}
