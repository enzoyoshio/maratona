#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n; string s;
	cin >> n >> s;
	for(int i = 0; i+2 < n; i++)
		if(s.substr(i, 3) == "ABC")
			return cout << i+1 << endl, 0;
	cout << -1 << endl;
}
