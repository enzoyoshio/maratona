#include <bits/stdc++.h>

using namespace std;
#define int long long

int fexp(int b, int e, int m) {
	if(e == 0) return 1LL;

	int x = fexp(b, e/2, m);
	x = (x*x)%m;
	if(e%2) x = (x*b)%m;
	return x;
}

struct Hash {
vector<int> mods = {
1000000009,1000000021,1000000033,
	        1000000087,1000000093,1000000097,
		        1000000103,1000000123,1000000181,
			        1000000207,1000000223,1000000241,
				        1000000271,1000000289,1000000297
};

vector<vector<int>> exp, inv, psum;
vector<vector<int>> h;
int p, n;

Hash() : p(3) {}

Hash(string s) {
p = 3;
n = s.size();
exp.resize(mods.size(), vector<int>(n+2));
inv.resize(mods.size(), vector<int>(n+2));
psum.resize(mods.size(), vector<int>(n+2));
h.resize(mods.size(), vector<int>(n+2));

for(int m = 0; m < mods.size(); m++) {
exp[m][0] = 1;
psum[m][0] = 1;
for(int i = 1; i < exp[m].size(); i++) {
exp[m][i] = (exp[m][i-1] * p)%mods[m];
	psum[m][i] = (exp[m][i]+psum[m][i-1])%mods[m];
				}

inv[m].back() = fexp(exp[m].back(), mods[m]-2, mods[m]);
for(int i = inv[m].size()-2; i >= 0; i--) {
			inv[m][i] = (inv[m][i+1] * p)%mods[m];
						}

	for(int i = 0; i < s.size(); i++) {
						h[m][i] = (s[i]-'0') * exp[m][i];
										h[m][i] %= mods[m];
														if(i) h[m][i] += h[m][i-1], h[m][i] %= mods[m];
																	}
			}

}

array<int, 15> query(int l, int r) {
array<int, 15> ans;
if(l == 0) {
for(int i = 0; i < mods.size(); i++)
ans[i] = h[i][r];
return ans;
}

for(int i = 0; i < mods.size(); i++)
ans[i] = ((((h[i][r] - h[i][l-1]))%mods[i] + mods[i])%mods[i] )%mods[i];
return ans;
}

};

signed main() {
cin.tie(0)->sync_with_stdio(false);

int t; cin >> t; while(t--) {
int n, m;
cin >> n >> m;
string s; cin >> s;
Hash h(s);

vector<int> ones(n);

for(int i = 0; i < n; i++) {
ones[i] = s[i] == '1';
if(i) ones[i] += ones[i-1];
}

/*
* 		for(int i = 0; i < 3; i++)
* 					cout << h.query(0, n-1)[i] << ' ' ; cout << endl;
* 								*/

set<array<int,15>> ans;
for(int i = 0; i < m; i++) {
int l, r; cin >> l >> r;
l--, r--;

array<int,15> first = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, last = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int q = (l ? ones[r] - ones[l-1] : ones[r]);
array<int, 15> sorted = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

if(q) {
for(int i = 0; i < h.mods.size(); i++)
	sorted[i] = ((h.psum[i][r] - h.psum[i][r-q])%h.mods[i] + h.mods[i])%h.mods[i];
							}

		if(l) {
							first = h.query(0, l-1);
										}

					if(r < n-1) {
//	for(auto it: h.h[0]) cout << it << ' '; cout << endl;
last = h.query(r+1, n-1);
}

/*
cout << "first\n";
for(int i = 0; i < h.mods.size(); i++) {
cout << first[i] << ' ';
}cout << endl;

cout << "sorted\n";
for(int i = 0; i < h.mods.size(); i++) {
cout << sorted[i] << ' ';
}cout << endl;


cout << "last\n";
for(int i = 0; i < h.mods.size(); i++) {
cout << last[i] << ' ';
}cout << endl;
*/


for(int i = 0; i <  h.mods.size(); i++) {
first[i] += (sorted[i])%h.mods[i];
first[i] %= h.mods[i];
first[i] += (last[i])%h.mods[i];
first[i] %= h.mods[i];
//	cout << first[i] << ' ';
}
//	cout << endl;

//cout << "final\n";
//cout << first[0] << ' ' << first[1] << ' ' << first[2] << endl;
ans.insert(first);
}
cout << ans.size() << '\n';
}
}
