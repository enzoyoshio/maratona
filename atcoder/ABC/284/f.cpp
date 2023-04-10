#include <bits/stdc++.h>

using namespace std;

vector<int> zfunction(string s) {
	int n = s.size();
	vector<int> z(n);

	int x = 0, y = 0;

	for(int i = 1; i < n; i++) {
		z[i] = max(0, min(z[i-x], y-i+1));
		while(i + z[i] < n && s[z[i]] == s[i+z[i]]) 
			x = i, y = i+z[i], z[i]++;
	}
	return z;
}

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n; string s;
	cin >> n >> s;

	string frente = s + "#";
	reverse(begin(s), end(s));
	frente += s;
	string tras = s + "#";
	reverse(begin(s), end(s));
	tras += s;

	auto zfrente = zfunction(frente);
	auto ztras = zfunction(tras);

	/*
	cout << frente << endl;
	for(auto el: zfrente)
		cout << el;
	cout << endl;

	cout << tras << endl;
	for(auto el: ztras)
		cout << el;
	cout << endl;
	*/

	for(int i = 0; i < 2*n; i++) {
		// pegar os idx do array reverso;
		int left = i;
		int right = i+n-1;
		int toRight = 2*n-right;

		/*
		cout << "------------------------------------------------------------\n";
		db(left);
		db(right);
		db(toRight);
		db(zfrente[(int)s.size() + toRight]);
		db((int)s.size() + toRight);
		db(ztras[(int)s.size() + i+1]);
		db((int)s.size() + i+1);
		*/
		if(zfrente[(int)s.size() + toRight] >= i && 
		   ztras[(int)s.size() + i+1] >= toRight-1) {
			string ans = s.substr(i, n);
			reverse(ans.begin(), ans.end());
			cout << ans << endl << i << endl;
			return 0;
		}	
	}
	cout << -1 << endl;
}
