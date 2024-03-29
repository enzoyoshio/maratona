#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n;
		cin >> n;
		map<int,int> ans;
		for(int i = 0; i < n; i++) {
			int a; cin >> a;
			ans[a]++;
		}

		while(ans.size() > 1 || ans.begin()->second > 1) {

			/*
			cout << "debugando o mapa -------------------->\n";
			for(auto [a, b]: ans) {
				cout << "elemento " << a << " tem " << b << " ocorrencias\n";
			}
			*/

			map<int,int> newmap;

			int last = -1;
			for(auto [num, freq]: ans) {
				if(~last)
					newmap[num-last]++;
				if(freq > 1)
					newmap[0] += freq-1;
				last = num;
			}
			swap(ans, newmap);
		}

		/*
		cout << "debugando o mapa -------------------->\n";
		for(auto [a, b]: ans) {
			cout << "elemento " << a << " tem " << b << " ocorrencias\n";
		}
		*/
		cout << ans.begin()->first << endl;
	}
}
