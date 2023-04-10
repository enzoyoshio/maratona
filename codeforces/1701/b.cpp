#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; cin >> t; while(t--) {
		int n;
		cin >> n;
		vector<int> used(n+1, false);
		vector<int> ans;

		for(int i = 1; i <= n; i++) {
			if(used[i]) continue;

			int cur = i;
			while(cur <= n) {
				used[cur] = true;
				ans.emplace_back(cur);
				cur *= 2;
			}
		}

		cout << 2 << endl;
		for(auto el: ans) cout << el << ' ';
		cout << endl;
	}
}
