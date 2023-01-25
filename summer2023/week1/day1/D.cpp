#include <bits/stdc++.h>

using namespace std;

const int oo = 1e8;

int main() {
    int f,s,g,u,d;
    cin >> f >> s >> g >> u >> d;

    queue<int> q;
    vector<int> dist(f+10, oo);
    dist[s] = 0;
    q.push(s);

    while(q.size()) {
        int cur = q.front(); q.pop();

        if(cur == g) {
            return cout << dist[cur] << endl, 0;
        }

        if(cur + u <= f && dist[cur+u] == oo) {
            q.push(cur+u);
            dist[cur+u] = dist[cur]+1;
        }

        if(cur - d > 0 && dist[cur-d] == oo) {
            q.push(cur-d);
            dist[cur-d] = dist[cur]+1;
        }

    }

    cout << "use the stairs\n";
}
