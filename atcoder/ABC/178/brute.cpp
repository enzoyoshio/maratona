#include <bits/stdc++.h>

using namespace std;
using iii = array<int, 3>;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> a(n), b(n);

	for(auto& it: a) cin >> it;
	for(auto& it: b) cin >> it;

	sort(begin(b), end(b));

	do {

		bool can = 1;

		for(int i = 0; i < n; i++) {
			if(a[i] == b[i]) can = 0;
		}

		if(can) {
			cout << "Yes\n";
			//for(auto el: b) cout << el << ' ';
			//cout << endl;
			return 0;
		}

	}while(next_permutation(begin(b), end(b)));
	cout << "No\n";
}
