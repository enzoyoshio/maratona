// had to read editorial
// the thing in this problem was to find out math solutions
// like 
// 1/k(k+1) = 1/k - 1/(k+1)
// with that, we can recursevely get an answer
//
// just be careful that if N = k(k-1) then it won't satisfy it
//
//
// ONE GIGANTIC NOTE THAT I SHOULD DO ABOUT THIS IS CONSIDER THINGS LIKE K AND K+!
// what i can do with consecutive elements i guess should help me a lil bit
#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	vector<vector<int>> ans(510);

	ans[1] = {1};
	ans[2] = {};

	vector<int> multiples(510);
	for(int i = 2; i < multiples.size(); i++) {
		multiples[i] = i*(i-1);
	}

	for(int i = 3; i < ans.size(); i++) {
		for(int k = 2; (int)ans[i].size()+1 < i; k++) {
			ans[i].push_back(multiples[k]);
		}

		ans[i].push_back(ans[i].size() + 1);

		auto p = lower_bound(begin(multiples), end(multiples), ans[i].back());

		if(p != end(multiples) && *p == ans[i].back()) {
			ans[i] = {};
			for(auto el: ans[i-1]) ans[i].push_back(el*2);
			ans[i].push_back(2);
		}
	}

	int t; cin >> t; while(t--) {
		int n;
		cin >> n;
		if(ans[n].empty()) {
			cout << "No\n";
			continue;
		}

		cout << "Yes\n";
		for(auto el: ans[n]) cout << el << ' ';
		cout << endl;
	}
}
