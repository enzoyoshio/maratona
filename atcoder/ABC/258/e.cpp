#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q, x;
	cin >> n >> q >> x;
	vector<int> v(n);
	for(auto& it: v)
		cin >> it;

	for(int i = 1; i < (int)v.size(); i++)
		v[i] += v[i-1];

	vector<int> frente, idxFrente;
	vector<int> ans, idxAns;

	map<int,int> vis;
	int idx = 0;

	while(!vis[idx]) {
		vis[idx] = 1;
		idxFrente.push_back(idx);
		
		int l = idx, r = (int)v.size()-1, ans = n-1;

		while(l <= r) {
			int mid = (l + r) >> 1;

			if(v[mid] - (idx ? v[idx-1] : 0) >= x) ans = mid, r = mid-1;
			else l = mid+1;
		}

		// so passar uma vez ja da
		if(v[ans] - (idx?v[idx-1]:0) >= x) {
			frente.push_back(ans-idx+1);	
			idx = (ans+1)%n;
			continue;
		}

		int falta = x - (v[ans] - (idx?v[idx-1]:0));

		int acum = ans-idx+1 + n * (falta / v.back());
		
		falta %= v.back();

		if(!falta) {
			frente.push_back(acum);
			idx = 0;
			break;
		}

		l = 0, r = (int)v.size()-1, ans = n-1;

		while(l <= r) {
			int mid = (l + r) >> 1;

			if(v[mid] >= falta) ans = mid, r = mid-1;
			else l = mid+1;
		}

		frente.push_back(acum + ans+1);
		idx = (ans+1)%n;
		
	}

	while(idxFrente.size() && idxFrente.back() != idx) {
		ans.push_back(frente.back());
		frente.pop_back();
		idxFrente.pop_back();
	}
	ans.push_back(frente.back());
	frente.pop_back();
	reverse(begin(ans), end(ans));

	while(q--) {
		int k; cin >> k;
		k--;
		if(k < (int)frente.size()) cout << frente[k] << endl;
		else cout << ans[(k-(int)frente.size())%(int)ans.size()] << endl;
		/*
		if(k < (int)frente.size()) cout << frente[k] << endl;
		else cout << ans[(k-(int)frente.size())%(int)ans.size()] << endl;
		*/
	}
}
