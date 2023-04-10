#include <bits/stdc++.h>

using namespace std;

int n, m;
string s, t;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int test; cin >> test; while(test--) {
		cin >> n >> m >> s >> t;

		int idxt = 0;

		for(int i = 0; i < n; i++)
			if(idxt < m && s[i] == t[idxt])
				idxt++;
		if(idxt != m) {
			cout << -1 << endl;
			continue;
		}

		cout << "processing\n";
	}
}
