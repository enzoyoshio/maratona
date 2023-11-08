#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> arv;
vector<int> pai, vis;
int first = -1, last;

void dfs(int u, int p) {
	pai[u] = p;
	vis[u] = 1;

	for(auto v: arv[u]) {
		if(vis[v]) {
			if(first == -1) {
				first = u;
				last = v;
			}

		}else {
			dfs(v, u);
		}
	}

}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n;
	arv.resize(n);
	pai.resize(n);
	vis.resize(n);
	
	for(int i = 0; i < n; i++) {
		int a; cin >> a; a--;
		arv[i].push_back(a);
	}

	for(int i = 0; i < n; i++) {
		if(!vis[i])
			dfs(i, i);
	}
	vector<int> ans;

	int idx = first;
	while(idx != last) {
		ans.push_back(idx);
		idx = pai[idx];
	}
	ans.push_back(last);
	reverse(begin(ans), end(ans));
	
	cout << ans.size() << endl;
	for(auto el: ans) cout << el+1 << ' ';
	cout << '\n';
}
