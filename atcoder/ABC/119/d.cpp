#include <bits/stdc++.h>

#define int long long

using namespace std;

const int oo = 1e15;

#define db(x) cout << "[ " << #x << " = " << x << " ]\n"

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int a, b, q;
    cin >> a >> b >> q;
    deque<int> shrine(a), temple(b);
    for(auto& it: shrine) cin >> it;
    for(auto& it: temple) cin >> it;

    shrine.emplace_front(-oo);
    shrine.emplace_back(oo);
    temple.emplace_front(-oo);
    temple.emplace_back(oo);

    auto choice = [&](int tem, int shr, int pos) {
        /* 
        cout << "\nI am debugging\n";
        db(tem);
        db(shr);
        db(pos);
        */
        int l = min({tem, shr, pos});
        int r = max({tem, shr, pos});
        int d1 = abs(pos-l), d2 = abs(pos-r);
        return 2*min(d1, d2) + max(d1, d2);
    };

    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;
        auto p = lower_bound(shrine.begin(), shrine.end(), x);
        auto t = lower_bound(temple.begin(), temple.end(), x);

        int ans = oo;
       
        ans = min(ans, choice(*p, *t, x));
        ans = min(ans, choice(*p, *prev(t), x));
        ans = min(ans, choice(*prev(p), *t, x));
        ans = min(ans, choice(*prev(p), *prev(t), x));

        cout << ans << endl;
    }
}
