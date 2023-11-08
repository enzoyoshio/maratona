#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		string s; cin >> s;

		bool can = true;
		vector<int> pos;

		for(auto ch: pos) {
			if(ch == '+') {
				if(pos.size() && (pos.back() == 0))
					pos.push_back(0);
				else
					pos.push_back(1);
			}else if(ch == '-') {
				pos.pop_back();
			}else if(ch == '1') {
				if(pos.size() && (pos.back() == 0)) {
					can = false;
					break;
				}
				if(pos.size())
					pos.back() = 2;
			}else if(ch == '0') {
				if((pos.size() < 2) 
				|| (pos.back() == 2)) {
					can = false;
					break;
				}
				pos.back() = 0;
			}
		}

		cout << (can ? "YES" : "NO") << '\n';
	}
}
