#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e3;
int n;
vector<int> unreachable, trapped;
vector<int> reached(MAXN, 0);
vector<int> from[MAXN], parent[MAXN];
vector<int> volta(MAXN);

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;

    vector<int> ordem(n);
    for(int i = 0; i < n; i++) {
        int cur; cin >> cur;
        ordem[i] = cur;
        int tam; cin >> tam;
        for(int j = 0; j < tam; j++) {
            int val; cin >> val; from[cur].push_back(val);
            parent[val].push_back(cur);
        }
    }

    for(int i = 0; i < MAXN; i++) reached[i] = 0;
    queue<int> q;
    q.push(0);
    reached[0] = 1;

    while(q.size()) {
        int cur = q.front(); q.pop();

        for(auto to: from[cur]) if(!reached[to]) {
            reached[to] = 1;
            q.push(to);
        }
    }

    for(int i = 0; i < n; i++) 
        if(!reached[ordem[i]]) unreachable.push_back(ordem[i]);

    q.push(0);
    for(int i = 0; i < MAXN; i++) reached[i] = 0;
    reached[0] = 1;

    while(q.size()) {
        int cur = q.front(); q.pop();

        for(auto pai: parent[cur]) if(!reached[pai]) {
            reached[pai] = 1;
            q.push(pai);
        }
    }  

    for(int i = 0; i < n; i++) {
        if(!reached[ordem[i]]) trapped.push_back(ordem[i]);
    }

    if(unreachable.empty() && trapped.empty()) cout << "NO PROBLEMS\n";
    else {
        // lembra de sortear baseado no q ele leu;
        for(auto it: trapped) cout << "TRAPPED " << it << endl;
        for(auto it: unreachable) cout << "UNREACHABLE " << it << endl;
    }
}
