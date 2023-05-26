#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"
 
const int MOD = 1e9+7;
int n;
string s;
int tb[20][2][11][2];
 
int dp(int idx=0, int lead=1, int prev=10, int only0=0) {
	
	if(idx >= n) {
		return 1;
	}
	
	auto& ans = tb[idx][lead][prev][only0];
	
	if(~ans) return ans;
	ans = 0;
	int mm = 9;
	
	if(lead) mm = s[idx]-'0';

	for(int i = 0; i <= mm; i++) {
		if(i != prev || (!i && !only0)) 
      ans += dp(idx+1, lead && i == mm, i, only0 || i);
	}
		
  /*
  cout << "\n------------ db ---------------\n";
  db(idx);
  db(lead);
  db(prev);
  db(mm);
  db(ans);
  */

	return ans;
}
 
signed main() {
	cin.tie(0)->sync_with_stdio(false);
 
	memset(tb, -1, sizeof(tb));
	int l, r; cin >> l >> r;
	
	if(!l) {
		s = to_string(r);
		n = s.size();
		cout << dp() << endl;
		return 0;
	}
	
	s = to_string(l-1);
	n = s.size();
	int left = dp();
	
	memset(tb, -1, sizeof(tb));
	s = to_string(r);
	n = s.size();
	int right = dp();
	
	cout << right - left << endl;
}
