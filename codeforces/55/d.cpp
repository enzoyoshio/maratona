#include <bits/stdc++.h>

using namespace std;
#define int long long

int n;
string s;
int tb[20][2][8][9][5][7][260];

bool is(int bit, int id) {
	return (1 << id) & bit;
}

vector<int> rev = {-1, -1, 0, 1, 2, 3, 4, 5, 6, 7};
vector<int> foi = {2, 3, 4, 5, 6, 7, 8, 9};

#define HERE tb[idx][lead][oito][nove][cinco][sete][bitmask]
int dp(int idx=0,
       bool lead=true,
       int oito=0,
       int nove=0, 
       int cinco=0, 
       int sete=0, 
       int bitmask=0) {

	/*
	cout << " here in state ";
	cout << idx << ' ';
	cout << lead << ' ';
	cout << dois << ' ';
	cout << tres << ' ';
	cout << cinco << ' ';
	cout << sete << ' ';
	cout << bitset<8>(bitmask).to_string() << "\n\n";
	*/

	if(idx >= n) {
		bool can = true;
		for(int i = 0; i < 8; i++) {
			if(is(bitmask, i)) {
				if(i == 0) {
					can &= (oito%2 == 0);
				}else if(i == 2) {
					can &= (oito%4 == 0);
				}else if(i == 6) {
					can &= oito == 0;
				}else if(i == 1) {
					can &= (nove%3 == 0);
				}else if(i == 3) {
					can &= cinco == 0;
				}else if(i == 4) {
					can &= (oito%2 == 0 && 
						nove%3 == 0);
				}else if(i == 5) {
					can &= sete == 0;
				}else if(i == 7) {
					can &= nove == 0;
				}
			}
		}
		/*
		if(!can) {
			cout << " here in state ";
			cout << idx << ' ';
			cout << lead << ' ';
			cout << oito << ' ';
			cout << nove << ' ';
			cout << cinco << ' ';
			cout << sete << ' ';
			cout << "can = " << can << ' ';
			cout << bitset<8>(bitmask).to_string() << "\n\n";
		}
		*/

		return can;
	}

	if(~HERE) return HERE;
	HERE = 0;
	int last = 9;
	if(lead) last = s[idx]-'0';

	int noito = (oito*10)%8;
	int nnove = (nove*10)%9;
	int ncinco = (cinco*10)%5;
	int nsete = (sete*10)%7;

	for(int i = 0; i <= last; i++) {
		bool nxt = (i == last && lead);
		int val;
		val = dp(idx+1, nxt, 
			(noito+i)%8, 
			(nnove+i)%9, 
			(ncinco+i)%5, 
			(nsete+i)%7, 
			bitmask | 
			(i == 0 || i == 1 ? 0 : (1 << rev[i])));
		//cout << "here before calling child " << HERE << endl;
		HERE += val;
		//cout << "state child " << val << endl;
		//cout << "here after dp " << HERE << endl;
		/*
		cout << "\n\n------------------ db ---------------\n";
		cout << idx << ' ' << i << endl;
		cout << bitset<8>(bitmask).to_string() << ' ';
		cout << (1 << rev[i]) << endl;
		*/
	}
	/*
	cout << "soma final ? ";
	cout << HERE << endl;
	cout << " here in state ";
	cout << idx << ' ';
	cout << lead << ' ';
	cout << oito << ' ';
	cout << nove << ' ';
	cout << cinco << ' ';
	cout << sete << ' ';
	cout << bitset<8>(bitmask).to_string() << "\n\n";
	*/

	return HERE;	
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	/*
	cin >> s;
	n = s.size();
	memset(tb, -1, sizeof tb);
	cout << dp() << endl;
	return 0;
	*/

	int t; cin >> t; while(t--) {

		int a; cin >> a;
		s = to_string(a-1);
		n = s.size();
		memset(tb, -1, sizeof tb);
	//	cout << " ================== calling for left ===== \n";
		int left = dp();

		cin >> s;
		n = s.size();
		memset(tb, -1, sizeof tb);
	//	cout << " \n\n================== calling for right ===== \n";
		int right = dp();

	//	cout << right << ' ' << left << endl;
		cout << right - left << '\n';
	}
}
