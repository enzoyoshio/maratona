#include <bits/stdc++.h>

using namespace std;

using t = tuple<int,int,int,int,int>;


int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<t> v(n);
	for(auto& [a, b, c, d, e]: v) cin >> a >> b >> c >> d >> e;

	multiset<int> cur;
	vector<int> as, bs, cs, ds, es;
	for(auto [a, b, c, d, e]: v) as.push_back(a), bs.push_back(b), cs.push_back(c), ds.push_back(d), es.push_back(e);
	sort(as.begin(), as.end());
	sort(bs.begin(), bs.end());
	sort(cs.begin(), cs.end());
	sort(ds.begin(), ds.end());
	sort(es.begin(), es.end());

	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			auto [a1, b1, c1, d1, e1] = v[i];
			auto [a2, b2, c2, d2, e2] = v[j];
		
			int putA, putB, putC, putD, putE;
			
			cur.clear();
			cur.insert(as.back());
			cur.insert(as[n-2]);
			cur.insert(as[n-3]);
			if(cur.find(a1) != cur.end()) 
				cur.erase(cur.find(a1));
			if(cur.find(a2) != cur.end())
				cur.erase(cur.find(a2));
			putA = *cur.rbegin();

			cur.clear();
			cur.insert(bs.back());
			cur.insert(bs[n-2]);
			cur.insert(bs[n-3]);
			if(cur.find(b1) != cur.end())
				cur.erase(cur.find(b1));
			if(cur.find(b2) != cur.end())
				cur.erase(cur.find(b2));
			putB = *cur.rbegin();

			cur.clear();
			cur.insert(cs.back());
			cur.insert(cs[n-2]);
			cur.insert(cs[n-3]);
			if(cur.find(c1) != cur.end())
				cur.erase(cur.find(c1));
			if(cur.find(c2) != cur.end())
				cur.erase(cur.find(c2));
			putC = *cur.rbegin();
			
			cur.clear();
			cur.insert(ds.back());
			cur.insert(ds[n-2]);
			cur.insert(ds[n-3]);
			if(cur.find(d1) != cur.end())
				cur.erase(cur.find(d1));
			if(cur.find(d2) != cur.end())
				cur.erase(cur.find(d2));
			putD = *cur.rbegin();

			cur.clear();
			cur.insert(es.back());
			cur.insert(es[n-2]);
			cur.insert(es[n-3]);
			if(cur.find(e1) != cur.end())
				cur.erase(cur.find(e1));
			if(cur.find(e2) != cur.end())
				cur.erase(cur.find(e2));
			putE = *cur.rbegin();

			int mi = min({max(a1, a2), max(b1, b2), max(c1, c2), max(d1, d2), max(e1, e2)});	

			if(mi == max(a1, a2)) {
				mi = min({max({a1, a2, putA}), max(b1, b2), max(c1, c2), max(d1, d2), max(e1, e2)});	
			}else if(mi == max(b1, b2)) {
				mi = min({max({a1, a2}), max({b1, b2, putB}), max(c1, c2), max(d1, d2), max(e1, e2)});	
			}else if(mi == max(c1, c2)) {
				mi = min({max({a1, a2}), max(b1, b2), max({c1, c2, putC}), max(d1, d2), max(e1, e2)});	
			}else if(mi == max(d1, d2)) {
				mi = min({max({a1, a2}), max(b1, b2), max(c1, c2), max({d1, d2, putD}), max(e1, e2)});	
			}else {
				mi = min({max({a1, a2}), max(b1, b2), max(c1, c2), max(d1, d2), max({e1, e2, putE})});	
			}
			ans = max(ans, mi);
		}
	}
	cout << ans << endl;
}
