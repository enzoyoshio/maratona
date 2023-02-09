#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;

    for(int i = 1; i < n; i++) {
        int j=0;
        while(j+i < n && s[j] != s[j+i])
            j++;
        cout << j << endl;
    }
}
