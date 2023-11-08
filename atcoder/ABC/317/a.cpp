#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int n, h, x;
	cin >> n >> h >> x;

	vector<int> v(n);

	for(int i = 0; i < n; i++) {

		cin >> v[i];

		if(h + v[i] >= x) return cout << i+1 << endl, 0;

	}
}
