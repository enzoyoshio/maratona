#include <bits/stdc++.h>

using namespace std;

int main() {
	int n = 2e5;

	cout << 1 << endl;
	cout << n << endl;

	int idx = 1;
	map<int,int> freq;
	int sq = sqrt(n);

	for(int i = 0; i < n; i++) {
		if(freq[idx] + 1 > sq) {
			idx++;
		}
		cout << idx << ' ';
		freq[idx]++;
	}
}
