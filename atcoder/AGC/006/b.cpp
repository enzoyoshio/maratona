#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, x;
	cin >> n >> x;

	if(x == 1 || x == 2*n-1) return cout << "No\n", 0;

	cout << "Yes\n";

	if(n == 2) return cout << "1\n2\n3\n", 0;

	set<int> free;
	for(int i = 1; i < 2*n; i++) free.insert(i);

	vector<int> ans(2*n-1);
	ans[2*n/2 -1] = x;
	free.erase(x);

	int l = 2*n/2-2, r = 2*n/2;
	ans[l--] = x-1;
	free.erase(x-1);
	ans[l--] = x+1;
	free.erase(x+1);

	if(x+2 < 2*n) {
		ans[r++] = x+2;
		free.erase(x+2);
	}else {
		swap(ans[l+1], ans[l+2]);
		ans[r++] = x-2;
		free.erase(x-2);
	}

	while(l >= 0) ans[l--] = *begin(free), free.erase(begin(free));
	while(r < 2*n && size(free)) ans[r++] = *begin(free), free.erase(begin(free));

	for(auto el: ans) cout << el << '\n';
}
