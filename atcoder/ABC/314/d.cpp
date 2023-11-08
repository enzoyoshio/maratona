#include <bits/stdc++.h>

using namespace std;

char uppercase(char c) {
	if(c >= 'a' && c <= 'z') return c-32;
	return c;
}

char lowercase(char c) {
	if(c >= 'A' && c <= 'Z') return c+32;
	return c;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q;
	string s;
	cin >> n >> s >> q;

	vector<int> last(n, -1);
	int lcase = -1, lastcase = -1;

	for(int i = 0; i < q; i++) {
		int t, x; char c;
		cin >> t >> x >> c;

		if(t == 1) {
			x--;
			s[x] = c;
			last[x] = i;
		}else if(t == 2) {
			lastcase = i;
			lcase = 0;
		}else {
			lastcase = i;
			lcase = 1;
		}
	}

	if(lastcase == -1) return cout << s << endl, 0;

	for(int i = 0; i < n; i++) {
		if(last[i] > lastcase) cout << s[i];
		else {
			if(lcase == 0) cout << lowercase(s[i]);
			else cout << uppercase(s[i]);
		}
	}
	cout << endl;
}
