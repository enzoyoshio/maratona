#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e10;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n;
		cin >> n;
		vector<int> a(n), c(n);
		vector<int> in(n);
		for(auto& it: a) {
			cin >> it, it--;
			in[it]++;
		}
		for(auto& it: c) cin >> it;

		queue<int> q;
		for(int i = 0; i < n; i++) {
			if(!in[i]) q.push(i);
		}

		vector<int> ans;
		vector<int> vis(n);
		while(q.size()) {
			auto cur = q.front(); q.pop();
			vis[cur] = true;
			ans.push_back(cur);

			in[a[cur]]--;
			if(!in[a[cur]]) q.push(a[cur]);	
		}

		for(int i = 0; i < n; i++) {
			if(vis[i]) continue;
			int maxn = oo;
			int idx = i;

			vector<int> toa;
			while(!vis[idx]) {
				vis[idx] = true;

				toa.push_back(idx);
				maxn = min(maxn, c[idx]);
				idx = a[idx];
			}

			for(int j = 0; j < toa.size(); j++) {
				if(c[toa[j]] == maxn) {
					for(int k = j+1; k < toa.size(); k++)
						ans.push_back(toa[k]);
					for(int k = 0; k <= j; k++)
						ans.push_back(toa[k]);
					break;
				}
			}
		}

		for(auto it: ans) cout << it+1 << ' ';
		cout << '\n';
	}
}
