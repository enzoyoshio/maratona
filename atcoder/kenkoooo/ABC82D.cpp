#include <bits/stdc++.h>

using namespace std;

string s;
int x, y;
int tb[800][800][800][4];

map<pair<int,int>, pair<int,int>> ccw = {
    {{1, 0}, {0, 1}},
    {{0, 1}, {-1, 0}},
    {{-1, 0}, {0, -1}},
    {{0, -1}, {1, 0}},
}, cw = {
    {{1, 0}, {0, -1}},
    {{0, -1}, {-1, 0}},
    {{-1, 0}, {0, 1}},
    {{0, 1}, {1, 0}},
};

map<pair<int,int>, int> volta = {
    {{1, 0}, 0},
    {{-1, 0}, 1},
    {{0, -1}, 2},
    {{0, 1}, 3}
};

vector<pair<int,int>> d = {
    {1, 0},
    {-1, 0},
    {0, -1},
    {0, 1}
};

int dp(int idx=0, int xx=0, int yy=0, int dir=0) {

    if(idx >= s.size()) {
        return xx == x && yy == y;
    }

    auto& ans = tb[idx][xx][yy][dir];

    if(~ans) return ans;

    if(s[idx] == 'F') {
        auto [x1, y1] = d[dir]; 
        return ans = dp(idx+1, xx+x1, yy+y1, dir); 
    }

    return ans = dp(idx+1, xx, yy, volta[ccw[d[dir]]]) || 
            dp(idx+1, xx, yy, volta[cw[d[dir]]]); 
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    memset(tb, -1, sizeof(tb));
    cin >> s >> x >> y;
    if(dp()) cout << "Yes\n";
    else cout << "No\n";
}
