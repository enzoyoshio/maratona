#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for(auto& it: v)
		cin >> it, it--;

	vector<int> called(n);
	set<int> ans;
	for(int i = 0; i < n; i++) {
		if(!called[i]) called[v[i]] = 1;
	}
	for(int i = 0; i < n; i++)
		if(!called[i]) ans.insert(i);
	cout << ans.size() << endl;
	for(auto el: ans)
		cout << el+1 << ' ';
	cout << endl;
}
