#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n; cin >> n;
		vector<int> v(n), orig;
		for(auto& it: v)
			cin >> it;
		orig = v;
		int qt = 2*n+10, counter = 0;
		while(qt > 2*n) {
			qt = counter++;
			v = orig;
			for(int i = n-2; i >= 0; i--) {
				while(v[i+1]%v[i] == 0) {
					v[i]++;
					qt++;
				}
			}
			orig.back()++;
		}
		for(auto el: v)
			cout << el << ' ';
		cout << endl;
	}
}
