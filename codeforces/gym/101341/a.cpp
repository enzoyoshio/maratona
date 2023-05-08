#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<string> v(n);
	vector<pair<int,int>> ans;

	for(auto& it: v)
		cin >> it;

	for(auto line: v) {
		int count = 0;
		for(auto ch: line)
			count += (ch == '(' ? -1 : 1);

		ans.emplace_back(count, (int)ans.size());
	}

	sort(ans.begin(), ans.end());

	int soma = 0;
	for(int i = 0; i < n; i++)
		soma += ans[i].first;

	if(soma)
		return cout << "NO\n", 0;

	cout << "YES\n";
	for(auto [a, b]: ans)
		cout << b+1 << ' ' ;
	cout << endl;

}
