#include <bits/stdc++.h>

using namespace std;

int main() {

	int n; cin >> n;
	vector<int> v(n);
	for(auto& it: v) cin >> it;
	sort(begin(v), end(v));

	for(int i = 1; i < n; i++) {
		if(abs(v[i]-v[i-1]) == 2) {
			return cout << v[i-1]+1 << endl, 0;
		}
	}
	cout << v.back() + 1 << endl;
}
