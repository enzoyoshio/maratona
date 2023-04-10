#include <bits/stdc++.h>

using namespace std;

int main() {

	int t; cin >> t; while(t--) {
		int n;
		cin >> n;
		vector<string> v(2*n-2);
		for(auto& it: v)
			cin >> it;
		sort(v.begin(), v.end(), [](string a, string b) {
				
					return a.size() < b.size();
				});

		bool can = true;
		for(int i = 0; i < 2*n-2; i += 2) {
			
			reverse(v[i+1].begin(), v[i+1].end());
//			cout << v[i] << ' ' << v[i+1] << endl;
			if(v[i] != v[i+1]) can = false;
		}

		cout << (can ? "yes" : "no") << endl;
	}
}
