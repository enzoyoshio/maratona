#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> y(n), r(n);

	while(q--) {
		int t, e;
		cin >> t >> e;
		e--;

		if(t == 1) {
			y[e]++;
		}else if(t == 2) {
			r[e]++;
		}else 
			cout << (y[e] == 2 || r[e] == 1 ? "Yes" : "No") << endl;

	}
}
