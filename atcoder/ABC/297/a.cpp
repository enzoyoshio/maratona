#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, d;
	cin >> n >> d;
	vector<int> v(n);
	for(auto& it: v)
		cin >> it;

	for(int i = 1; i < n; i++) {
		if(abs(v[i] - v[i-1]) <= d) {
			return cout << v[i] << endl, 0;
		}
	}

	cout << -1 << endl;
}
