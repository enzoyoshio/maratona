#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int w;
	cin >> w;

	vector<int> ans;
	for(int i = 1; i < 100; i++) {
		ans.push_back(i);
		ans.push_back(i*100);
		ans.push_back(i*10000);
	}
	ans.push_back(1000000);
	sort(begin(ans), end(ans));

	while(ans.back() > 1000000)
		ans.pop_back();

	cout << ans.size() << endl;
	for(auto el: ans)
		cout << el << ' ';
	cout << endl;
}
