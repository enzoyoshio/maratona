#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {

	int t; cin >> t; while(t--) {
		int n;
		cin >> n;
		vector<vector<int>> f(55), mat(n);

		for(int i = 0; i < n; i++) {
			int tam; cin >> tam;
			for(int j = 0; j < tam; j++) {
				int a; cin >> a;
				mat[i].push_back(a);
				f[a].push_back(i);
			}
		}

		int all = 0;
		for(int i = 0; i < 55; i++)
			all += !f[i].empty();

		auto take = [&](vector<int> no) {
			int idx = 0;
			vector<bool> on(55);
			for(int i = 0; i < n; i++) {
				if(idx < no.size() &&
				   no[idx] == i) {
					idx++;
					continue;
				}

				for(int j = 0; j < mat[i].size(); j++)
					on[mat[i][j]] = 1;
				
			}
			return accumulate(begin(on), end(on), 0LL)%all;
		};

		int ans = 0;
		for(int i = 1; i <= 50; i++) {
			ans = max(ans, take(f[i]));	
		}
		cout << ans << endl;
	}
}
