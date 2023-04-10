#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<pair<int,int>> ans;

	for(int i = 1; i < n; i++) {
		ans.emplace_back(0, i);	
	}

	int cur = (n-1)*(n-2)/2;

	for(int i = 1; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			if(cur > k) ans.emplace_back(i, j), cur--;
		}
	}

	if(cur-k) return cout << -1 << endl, 0;

	cout << ans.size() << endl;

	for(auto [a, b]: ans)
		cout << a+1 << ' ' << b+1 << endl;
}
