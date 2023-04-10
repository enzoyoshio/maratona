#include <bits/stdc++.h>

using namespace std;

using ll = long long;
vector<string> grid(8);

ll look(int level=0, set<int> col={}, set<int> diag1={}, set<int> diag2={}) {

	if(level >= 8)
		return 1LL;

	int ans = 0;
	for(int i = 0; i < 8; i++) {
		if(col.count(i) || diag1.count(i+level) || diag2.count(i-level) || grid[level][i] == '*') 
			continue;

		col.insert(i);
		diag1.insert(i+level);
		diag2.insert(i-level);
		ans += look(level+1, col, diag1, diag2);
		col.erase(i);
		diag1.erase(i+level);
		diag2.erase(i-level);
	}

	return ans;
}

int main() {
	for(auto& line: grid)
		cin >> line;

	cout << look() << endl;	
}
