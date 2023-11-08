#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m; string s, t;
	cin >> n >> m >> s >> t;

	if(s.substr(0, n) == t.substr(0, n) &&
	   s.substr(0, n) == t.substr(m-n, n)) cout << 0 << endl;
	else if(s.substr(0, n) == t.substr(0, n)) cout << 1 << endl;
	else if(s.substr(0, n) == t.substr(m-n, n)) cout << 2 << endl;
	else cout << 3 << endl;
}
