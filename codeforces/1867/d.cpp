#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		for(auto& it: v) cin >> it;

		if(k == 1) {
			vector<int> p(n);
			iota(begin(p), end(p), 1LL);
			if(p == v) cout << "Yes\n";
			else cout << "No\n";
			continue;
		}

		bool can = true;
		for(int i = 0; i < n; i++) {
			if(i+1 == v[i]) can = false;
		}

		if(!can) {
			cout << "No\n";
			continue;
		}

		for(int i = 0; i < n; i++) v[i]--;
		vector<int> in(n);
		for(int i = 0; i < n; i++) in[v[i]]++;

		queue<int> q;
		for(int i = 0; i < n; i++) if(!in[i]) q.push(i);

		vector<int> vis(n, false);

		while(q.size()) {
			auto u = q.front();
			q.pop();
			vis[u] = 1;

			in[v[u]]--;
			if(!in[v[u]]) q.push(v[u]);
		}

		can = true;
		for(int i = 0; i < n; i++) {
			if(!vis[i]) {
				int idx = i, c = 0;
				
				while(!vis[idx]) {
					c++;
					vis[idx] = true;
					idx = v[idx];
				}
				if(c != k) can = false;
			}
		}

		if(can) cout << "Yes\n";
		else cout << "No\n";
	}
}
