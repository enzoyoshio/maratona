#include <bits/stdc++.h>

#define int long long
#define db(x) cout << "[ " << #x << " = " << x << " ]\n"

using namespace std;

const int oo = 1e15;
const int MAXN = 1e6 +3;
int n;
vector<tuple<int,int,int>> v;
vector<int> ord;
vector<int> st(4*MAXN, -oo);

int find(int x) {
    return lower_bound(ord.begin(), ord.end(), x) - ord.begin();
}

void update(int idx, int val, int sti=1, int stl=0, int str=n-1) {
    if(idx > str || idx < stl) return;

    if(stl == str) {
        st[sti] = max(st[sti], val);
        return;
    }

    int mid = (stl+str) >> 1, e = (sti) << 1, d = (sti << 1) + 1;

    update(idx, val, e, stl, mid);
    update(idx, val, d, mid+1, str);
    st[sti] = max(st[e], st[d]);
}

int query(int A, int B, int sti=1, int stl=0, int str=n-1) {
    if(B < A) return -oo;
    if(A > str || B < stl) return -oo;

    if(A <= stl && str <= B) return st[sti];

    int mid = (stl+str) >> 1, e = sti << 1, d = (sti << 1) + 1;

    return max(query(A, B, e, stl, mid), query(A, B, d, mid+1, str));
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    v.assign(n, {});

    for(auto& [a, b, c]: v)
        cin >> a >> b >> c, ord.push_back(a), ord.push_back(b);

    sort(v.begin(), v.end());
    sort(ord.begin(), ord.end());
    n = ord.size();

    for(auto [left, right, val]: v) {
        /*
        cout << "\n\ndebug\n";
        db(left);
        db(right);
        db(val);
        */
        int adiciona = max(0LL, query(0, find(left)-1));

        update(find(right), adiciona + val);
    }

    cout << query(0, n-1) << endl;
}
