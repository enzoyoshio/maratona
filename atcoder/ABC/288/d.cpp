#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> v(n), dif(n);
	for(auto& it: v) cin >> it;

	for(int i = 0; i < n; i++) {
		if(!i) dif[i] = v[i];
		else dif[i] = v[i] - v[i-1];
	}
	vector<vector<int>> psum(n, vector<int>(k));
	for(int i = 0; i < n; i++) {
		if(i == 0) psum[i][i] = dif[i];
		else {
			psum[i] = psum[i-1];
			psum[i][i%k] += dif[i];
		}
	}

	/*
	cout << "difs\n";
	for(auto it: dif) cout << it << ' '; cout << endl;
	cout << "psums\n";
	for(auto it: psum) cout << it << ' '; cout << endl;
	*/
	
	int q; cin >> q;
	while(q--) {
		int l, r; cin >> l >> r;
		l--, r--;

		if(k == 1) {
			cout << "Yes\n";
			continue;
		}

		auto qs = psum[r];

		for(int i = 0; i < k; i++) qs[i] -= psum[l][i];
		qs[l%k] += v[l];
		qs[(r-k+1)%k] = 0; // i did not get this line

		bool can = true;
		for(auto el: qs) can &= el == 0;
		cout << (can ? "Yes" : "No") << '\n';
	}
}
// this is a solution STRONGLY based in cebolinha's solution
// and also a lot of editorial reading
// I understood the part of differential arrays and using preffix sums
// but somehow I still don't get it why it works
// when we are querying things, I guess I don't know
// should think about this more?
// like, before reading editorial I thought about differential array
// but didn't come up with anything because like, it didn't seem straight
// forward to just sum up everything, actually I compute de differential 
// array but did not realize that when you make a operation, you only
// affect jumps of K (although after you discover that, it seems pretty clear)
// that part of editorial I understood, the operation basically does 
// +c -c in the differential array, and if we sum up everything 
// (but just sums everything that is same modulo K)
// than if we apply the operation it really doesn't change anything,
// because +c -c in a cumulative sum won't make a difference
// ok. that part I got. 
// and do a preffix sum modulo K it's ok.
// but the part I didn't get was that like, when I have a subarray of it
// how can I measure it? like why does Quirino adds the full value of 
// the first element ? Maybe I'm just dumb? 
// and why he sets to zero the first guy after r-k ? 
// oh I just give up, I hope one day I get to be good like this people
