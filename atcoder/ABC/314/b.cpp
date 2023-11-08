#include <bits/stdc++.h>

int main() {
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> rou(n);

	for(int i = 0; i < n; i++) {
		int t; std::cin >> t;
		rou[i].push_back(t);
		for(int j = 0; j < t; j++) {
			int a; std::cin >> a;
			rou[i].push_back(a);
		}
	}

	int x, len=110;
	std::cin >> x;

	std::vector<int> ans;

	for(int i = 0; i < n; i++) {
		if(find(begin(rou[i])+1, end(rou[i]), x) != end(rou[i]) && rou[i][0] <= len) {
			if(rou[i][0] < len) ans.clear();
			len = rou[i][0];
			ans.push_back(i+1);
		}
	}
	std::cout << ans.size() << std::endl;
	for(auto it: ans) std::cout << it << ' ';
	std::cout << std::endl;
}
