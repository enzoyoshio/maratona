#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	string s;
	cin >> s;
	for(int i = 0; i < (int)s.size(); i+=2)
		swap(s[i], s[i+1]);
	cout << s << endl;
}
