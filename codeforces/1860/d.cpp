#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e18;

using iiii = array<int,4>;
using iii = array<int,3>;
int n;
int ct;
string s;
unordered_map<int,int> tab;
//map<iii, int> tab;

#define HERE tab[(idx) | (zeros << 10) | (endZ<<20)]
int dp(int idx, int zeros, int endZ) {

	if(idx >= n) {
		if(zeros != ct || endZ) return oo;
		return 0;
	}

	if(tab.find((idx) | (zeros << 10) | (endZ << 20)) != end(tab)) return HERE;

	int um = oo, zero = oo;

	// terminando em 1
	um = (s[idx] != '1') + dp(idx+1, zeros, endZ - zeros);

	// terminando em 0
	int leftOnes = idx - zeros;
	zero = (s[idx] != '0') + dp(idx+1, zeros+1, endZ + leftOnes);

	/*
	cout << "\n\nstate " << idx << ' ' << zeros << ' ' << endZ << ' ' << endl;
	cout << um << ' ' << zero << endl;
	*/
	return HERE = min(um, zero);
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t = 1; 
	while(t--) {
		cin >> s;
		n = s.size();
		tab.clear();
		ct = 0;
		for(auto ch: s) ct += ch == '0';

		cout << dp(0, 0, 0)/2 << '\n';
	}
}
