#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector v(n, vector<int>(m));
	for(auto& l: v)
		for(auto& it: l)
			cin >> it, it--;

	int ans = 2*n;
	vector idx(n, 0);
	vector used(m, 0);
	vector f(m, 0);

	while(true) {

		bool can = true;
		for(int i = 0; i < m; i++)
			if(!used[i]) can = false;
		if(can) break;

		for(int i = 0; i < n; i++) {
			while(idx[i] < m && used[v[i][idx[i]]]) idx[i]++;
		}

		int cur = -1;
		int el = -1;
		for(int i= 0; i < m; i++)
			f[i] = 0;
		
		for(int i = 0; i < n; i++) {
			if(idx[i] < m) {
				auto& here = f[v[i][idx[i]]];
				here++;

				if(here > cur) {
					cur = here;
					el = v[i][idx[i]];
				}
			}
		}

		ans = min(ans, cur);
		used[el] = 1;
	}
	cout << ans << endl;
}
