#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n, m;
		cin >> n >> m;
		vector<int> v(m), needed(n);
		for(auto& it: v) cin >> it, it--, needed[it]++;

		if(n == 1) {
			cout << m << endl;
			continue;
		}

		multiset<int> timer;
		for(int i = 0; i < n; i++) {
			timer.insert(needed[i]);
		}

		while(*timer.begin()+2 < *timer.rbegin()) {
			auto ini = *timer.begin();
			auto fim = *prev(timer.end());

			timer.erase(timer.begin());
			timer.erase(prev(timer.end()));
			timer.insert(ini + 2);
			timer.insert(fim-1);
		}
		cout << *timer.rbegin() << endl;
	}
}
