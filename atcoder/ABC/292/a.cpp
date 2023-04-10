#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	for(auto ch: s)
		cout << char(ch-'a'+'A');
	cout << endl;
}
