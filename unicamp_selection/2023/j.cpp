#include <bits/stdc++.h>

using namespace std;
#define int long long

using iii = array<int,3>;

int n;
vector<int> v, psum;
vector<vector<int>> tab;

int dp(int l, int r) {

	if(r < l) return 0;

	if(r == l) return v[r];

	auto& ans = tab[l][r];
	if(~ans) return ans;
	ans = 0;

	// pegar da esquerda -> novo range [l+1, r]
	int nr = r, nl = l+1;
	if(v[nl] > v[nr]) nl++;
	else nr--;

	auto left = v[l] + dp(nl, nr);

	if(left > ans) {
		ans = left;
	}


	int nr1 = r-1, nl1 = l;
	if(v[nl1] > v[nr1]) nl1++;
	else nr1--;

	auto right = v[r] + dp(nl1, nr1);
	if(right > ans) {
		ans = right;
	}

	/*
	cout << "dp " << l << ' ' << r << " ans = " << ans << endl;
	cout << "left = " << left << endl;
	cout << "nl = " << nl << " nr = " << nr << endl;
	cout << "righ = " << right << endl;
	cout << "nl1 = " << nl1 << " nr1 " << nr1 << endl;
	*/
	return ans;
}

string gera = "";
void gen(int l, int r, int need) {

	if(l > r) return;

	// pegar da esquerda -> novo range [l+1, r]
	int nr = r, nl = l+1;
	if(v[nl] > v[nr]) nl++;
	else nr--;

	auto left = v[l] + dp(nl, nr);

	if(left >= need) {
		gera += 'L';
		gen(nl, nr, need-v[l]);
		return;
	}

	int nr1 = r-1, nl1 = l;
	if(v[nl1] > v[nr1]) nl1++;
	else nr1--;

	auto right = v[r] + dp(nl1, nr1);
	if(right >= need) {
		gera += 'R';
		gen(nl1, nr1, need-v[r]);
	}
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	n *= 2;
	v.resize(n);
	tab.resize(n, vector<int>(n, -1));
	psum.resize(n);
	for(auto& it: v) cin >> it;

	for(int i = 0; i < n; i++) {
		psum[i] = v[i];
		if(i) psum[i] += psum[i-1];
	}

	int full = accumulate(begin(v), end(v), 0LL);
	int res = dp(0, n-1);

	/*
	cout << "max = " << res << endl;
	cout << "total sum = " << full << endl;
	*/

	// this dp works for this 2 cases
	if(res+1 < full-res) return cout << ":(\n", 0;
	if(res+1 == full-res) return cout << "tie\n", 0;

	// what do i do here? like ? wtf
	cout << "TECHNOBLADE NEVER DIES!" << endl;

	gen(0, n-1, (full+1)/2);

	cout << gera << endl;
}
