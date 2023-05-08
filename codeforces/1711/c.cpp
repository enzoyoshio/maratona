#include <bits/stdc++.h>

#define int long long

using namespace std;

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> v(k);
		for(auto& it: v)
			cin >> it;

		auto check = [](int n, int m, vector<int>& v) {

			bool mIsOdd = m%2;
			bool has3 = false;
			for(int i = 0; i < (int)v.size(); i++) {
			
				int qt = v[i]/n;

				if(qt > 1) {
					m -= qt;
				}
				if(qt > 2) has3 = true;
			}

			if(mIsOdd && has3 && m <= 0)
				return true;
			else if(!mIsOdd && m <= 0)
				return true;
			else return false;	
		};

		if(check(n, m, v) || check(m, n, v)) cout << "Yes\n";
		else cout << "No\n";
		
	}
}
