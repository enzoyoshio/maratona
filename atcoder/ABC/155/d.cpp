#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e18;

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"

int n, k;
vector<int> v;

bool check(int target) {
	int qt = 0;
	for(int i = 0; i < n; i++) {

		if(v[i] == 0) {
			if(target <= 0) qt += n-i-1;
			continue;
		}else if(v[i] > 0) {
			int bl = i+1, br = n-1, bans = n;
			// busca binaria -> quantos elementos sao maiores ou iguais a target
			while(bl <= br) {
				int bmid = (bl + br)/2;
				
				if(v[i]*v[bmid] >= target) bans = bmid, br = bmid-1;
				else bl = bmid+1;
			}
			qt += n-bans;
		}else {
			int bl = i+1, br = n-1, bans = i;
			while(bl <= br) {
				int bmid = (bl + br)/2;

				if(v[i] * v[bmid] >= target) bans = bmid, bl = bmid+1;
				else br = bmid-1;
			}
			qt += bans-i;
		}
	}

//	db(qt);
	return qt >= k;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> k;
	k = n*(n-1)/2 - k+1;
//	db(k);
	v.resize(n);
	for(auto& it: v) cin >> it;
	sort(begin(v), end(v));

	/*
	for(auto it: v) cout << it << ' ';
	cout << endl;

	for(int i = 0; i+1 < n; i++) {
		cout << "multiple of i = " << i << " v[i] = " << v[i] << endl;
		for(int j = i+1; j < n; j++)
			cout << v[i]*v[j] << ' ';
		cout << endl;

	}
	*/

	int bl = -oo; //min(v[0]*v[1], v[0]*v.back());
	int br = oo; //max(v.back()*v[n-2], v.back() * v[0]);
	int bans = -1;

	while(bl <= br) {
		int bmid = (bl + br)/2;

		/*
		cerr << "----------------------- first bb -----------------\n";
		db(bmid);
		db(bl);
		db(br);
		*/
		
		if(check(bmid)) bans = bmid, bl = bmid+1;
		else br = bmid-1;
	}

	cout << bans << endl;
}
