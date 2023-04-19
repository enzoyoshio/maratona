#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, c;
	cin >> n >> c;
	vector<pair<int, int>> v(n);
	for(auto& [a, b]: v)
		cin >> a >> b;

	int andd = (1 << 31)-1;
	int orr = 0;
	int xorr = 0;
	for(int i = 0; i < n; i++) {
		if(v[j].first == 1) {
			andd &= v[j].second;
		}else if(v[j].first == 2) {
			orr |= v[j].second;
		}else {
			xorr ^= v[j].second;
		}

		for(int 
			
		cout << c << endl;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			if(v[j].first == 1) 
				c &= v[j].second;
			else if(v[j].first == 2) 
				c |= v[j].second;
			else 
				c ^= v[j].second;
		}
		cout << c << endl;
	}
}

// mask of ands = and of all up to here
// mask of or   = 
// xor xor of everyone up to here

