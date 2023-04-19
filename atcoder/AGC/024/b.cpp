#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n), pos(n);
	for(int i = 0; i < n; i++) {
		int a; cin >> a; a--;
		v[i] = a;
		pos[a] = i;
	}

	int cur = 1, ans = 0;

	for(int i = 1; i < n; i++) {
		if(pos[i] < pos[i-1]) {
			ans = max(ans, cur);
			cur = 1;
		}else {
			cur++;
		}
	}
	ans = max(ans, cur);

	cout << n-ans << endl;
}
