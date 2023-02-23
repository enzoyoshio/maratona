#include <bits/stdc++.h>

#define int long long

using namespace std;

#define db(x) cout << "[ " << #x << " = " << x << " ]\n"

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int x, y, z, k;
    priority_queue<tuple<int,int,int,int>> pq;
    set<tuple<int,int,int>> seen;
    priority_queue<int> ans;

    cin >> x >> y >> z >> k;

    vector<int> a(x), b(y), c(z);
    for(auto& it: a)
        cin >> it;
    for(auto& it: b)
        cin >> it;
    for(auto& it: c)
        cin >> it;

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());

    pq.emplace(a[0] + b[0] + c[0], 0, 0, 0);
    seen.emplace(0, 0, 0);

    while(ans.size() < 10*k) {
        auto [val, id1, id2, id3] = pq.top(); pq.pop();

        /*
        cout << "\n\n";
        db(val);
        db(id1);
        db(id2);
        db(id3);
        */

        ans.push(val);

        if(seen.find({id1+1, id2, id3}) == seen.end() && id1+1 < x) {
            seen.emplace(id1+1, id2, id3);
            pq.emplace(a[id1+1] + b[id2] + c[id3], id1+1, id2, id3);
        }

        if(seen.find({id1, id2+1, id3}) == seen.end() && id2+1 < y) {
            seen.emplace(id1, id2+1, id3);
            pq.emplace(a[id1] + b[id2+1] + c[id3], id1, id2+1, id3);
        }

        if(seen.find({id1, id2, id3+1}) == seen.end() && id3+1 < z) {
            seen.emplace(id1, id2, id3+1);
            pq.emplace(a[id1] + b[id2] + c[id3+1], id1, id2, id3+1);
        }
    }

    while(k--)
        cout << ans.top() << endl, ans.pop();
}
