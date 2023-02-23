#include <bits/stdc++.h>

using namespace std;

int main() {
    int l, r, a;
    cin >> l >> r >> a;

    if(min(l, r) + a <= max(l, r)) cout << 2*(min(l, r)+a) << endl;
    else cout << 2*max(l, r) + (a-abs(l-r))/2*2 << endl;
}
