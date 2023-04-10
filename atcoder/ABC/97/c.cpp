#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	string s;
	cin >> s >> n;

	set<string> se;
	for(int i = 0; i < (int)s.size(); i++) {
		for(int j = i; j < i+10; j++) {
			se.insert(s.substr(i, j-i+1));
		}
	}

	string ans;
	while(n--)
		ans = *se.begin(), se.erase(se.begin());
	cout << ans << endl;
}
