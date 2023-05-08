#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9;
const int MAXN = 1e5 + 8;
int n, k; 
vector<int> v(MAXN);
vector<int> divi;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		cin >> n >> k;
		for(int i = 0; i < n; i++)
			cin >> v[i];
	
		int mx = *max_element(begin(v), end(v)), mn = *min_element(begin(v), end(v));

		if(k*2 > *max_element(begin(v), end(v)) || n == 1) {
			cout << 0 << endl;
			continue;
		}

		divi.clear();
		for(int i = 1; i <= k; i++) {
			if(divi.empty() || divi.back() != v[0]/i) divi.push_back(v[0]/i);
		}

		int ans = oo;
		for(auto l: divi) {
			if(!l) {
				int cur = 0;
				for(int i = 1; i < n; i++)
					cur = max(cur, v[i]/k);

				ans = min(cur, ans);
				continue;
			}
			int cur = 0;
			/*
			cout << "--------------------------------\n";
			cout << "l = " << l << endl;
			*/
			for(int i = 1; i < n; i++) {

				int el = (v[i])/l;

				/*
				cout << "el = " << el << endl;
				cout << "v[i] = " << v[i] << endl;
				cout << "el * v[i] = " << el* v[i] << endl;
				cout << "el * l = " << el*l << endl;
				cout << "v[i]/el = " << v[i]/el << endl;
				cout << endl << endl;
				*/

				el = min(el, k);
				cur = max(cur, v[i]/el);

			}
			ans = min(ans, abs(cur-l));
		}

		cout << ans << endl;
	}

}
