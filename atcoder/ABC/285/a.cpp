#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if(a > b) swap(a, b);

    if(b/2 == a) cout << "Yes\n";
    else cout << "No\n";
}
