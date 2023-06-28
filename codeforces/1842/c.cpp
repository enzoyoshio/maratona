#include <bits/stdc++.h>

using namespace std;

#define int long long
const int oo = 1e8;

/*
int dp(int idx, int last_taken) {

	if(idx >= n) return (last_taken != 0) * oo;

	int pega = oo, npega = oo;

	// nao ta no meio de nenhum intervalo
	if(last_taken == 0) {
		pega = dp(idx+1, idx);
		npega = 1 + dp(idx+1, last_taken);
		return min(pega, npega);
	}

	if(v[idx] == v[last_taken]) {
		pega = dp(idx+1, 0);
	}
	npega = dp(idx+1, last_taken); 

	return min(pega, npega);
}
*/

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for(auto& it: v) cin >> it, it--;

		vector<int> freq(n);
		bool zero = false;
		int maxfreq = 0;
		for(auto it: v) {
			if(++freq[it] > 1) {
				zero = true;
			}
			maxfreq = max(maxfreq, freq[it]);
		}

		// se for permutacao
		if(!zero) {
			cout << 0 << '\n';
			continue;
		}

		// kinda stress tested it and it worked
		vector<int> pos[n];
		vector<int> dp_not(n);
		vector<int> dp_ending(n);
		dp_not[0] = 1; // o minimo numero de bolas retiradas eh i+1
		dp_ending[0] = 1;
		pos[v[0]].push_back(0);
		for(int idx = 1; idx < n; idx++) {
		
			dp_ending[idx] = oo;
			dp_not[idx] = min(idx+1, dp_not[idx-1]+1);
			dp_not[idx] = min(dp_not[idx], dp_ending[idx-1]+1);

			for(auto p: pos[v[idx]]) {
				dp_ending[idx] = min(dp_ending[idx], dp_not[p]-1);
			}

			pos[v[idx]].push_back(idx);
		}

		/*
		for(auto it: dp_not) cout << it << ' ';
		cout << endl;
		for(auto it: dp_ending) cout << it << ' ';
		cout << endl;
		*/

		cout << n - min(dp_not.back(), dp_ending.back()) << '\n';
	}
}
