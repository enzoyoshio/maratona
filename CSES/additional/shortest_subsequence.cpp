#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	string s;
	cin >> s;
	set<char> chunks;
	string ans = "";

	for(int i = 0; i < s.size(); i++) {
		chunks.insert(s[i]);

		if(chunks.size() == 4) {
			ans += s[i];
			chunks.clear();
		}
	}

	if(chunks.empty()) ans += ans.back();
	else {
		string acgt = "ACGT";
		for(auto ch: acgt) {
			if(chunks.find(ch) == chunks.end()) {
				ans += ch;
				break;
			}
		}
	}

	cout << ans << endl;
}
