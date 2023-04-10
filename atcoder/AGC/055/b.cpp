#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	string s, t;
	cin >> s >> t;

	vector<int> f(3, 0);
	for(auto& ch: s) f[ch-'A']++;
	for(auto& ch: t) f[ch-'A']--;

	if(*max_element(begin(f), end(f)) || *min_element(begin(f), end(f))) return cout << "NO\n", 0;

	
}
