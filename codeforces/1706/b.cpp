#include <bits/stdc++.h>

using namespace std;

int main() {
//	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n;
		cin >> n;
		vector<vector<int>> freq(n, vector<int>());
		for(int i = 0; i < n; i++) {
			int a; cin >> a;
			a--;
			freq[a].push_back(i);
		}

		vector<int> ans(n);

		for(int i = 0; i < n; i++) {
			if(freq[i].empty()) continue;

			int cur = 1;

			for(int j = 1; j < (int)freq[i].size(); j++) {
				int val = freq[i][j] - freq[i][j-1];
				if(val%2) cur++;
			}	
			ans[i] = cur;
		}

		for(auto& el: ans)
			cout << el << ' ';
		cout << endl;
	}
}
