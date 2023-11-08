#include <bits/stdc++.h>

using namespace std;
#define int long long

// returns true if first player Takahashi wins 
// the game
bool f(string s, bool taka=true) {

	if(size(s) == 3) {
		bool ans;
		if(s[0] == s.back()) ans = false;
		else ans = true;
		if(!taka) ans = !ans;
		return ans;
	}	

	vector<bool> pos;
	bool can = true;
	if(taka) {
		can = false;
		for(int i = 1; i < size(s) - 1; i++) {
			if(s[i-1] != s[i+1]) {
				bool next = f(s.substr(0, i) + s.substr(i+1), !taka);
				pos.push_back(next);
				can|= next;
			}
		}
	}else {
		can = true;

		for(int i = 1; i < size(s) -1; i++) {
			if(s[i-1] != s[i+1]) {
				bool next = f(s.substr(0, i) + s.substr(i+1), !taka);
				pos.push_back(next);
				can &= next;
			}
		}
	}

//	cout << s << ' ' << taka << ' ' << can << endl;
	return can;

}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	string s;
	cin >> s;

	// eu acho que eles sempre conseguem deixar 
	// apenas duas coisas
	// entao se a primeira e ultima forem iguais, 
	// quem joga por ultimo perde
	// se as duas forem diferente
	// quem joga por ultimo ganha
	if(s[0] == s.back()) {
		if(s.size()%2) cout << "Second" << endl;
		else cout << "First" << endl;
	}else {
		if(s.size()%2) cout << "First" << endl;
		else cout << "Second" << endl;
	}
}
