#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;

	set<char> vs;

	int ans = 0;
	for(auto ch: s) {
		if(vs.size() == 3) break;
		vs.insert(ch);
		ans++;
	}
	cout << ans << endl;

}
