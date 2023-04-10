#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;cin >> s;

	vector<int> rocks, bishops, king;
	for(int i = 0; i < (int)s.size(); i++) {
		if(s[i] == 'K') king.push_back(i);
		else if(s[i] == 'R') rocks.push_back(i);
		else if(s[i] == 'B') bishops.push_back(i);	
	}

	if(bishops[0]%2 != bishops.back()%2 && rocks[0] < king[0] && king[0] < rocks.back()) cout << "Yes\n";
	else cout << "No\n";
}
