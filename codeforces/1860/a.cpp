#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		string s;
		cin >> s;
		int tam = 0;

		string s1 = "", s2 = "";
		for(int i = 0; i < s.size(); i++)
			s1 += "()", s2 += "(";
		for(int i = 0; i < s.size(); i++)
			s2 += ")";

		if(s1.find(s) == string::npos) cout << "YES\n" << s1;
		else if(s2.find(s) == string::npos) cout << "YES\n" << s2;
		else cout << "NO";
		cout << '\n';

	}
}
