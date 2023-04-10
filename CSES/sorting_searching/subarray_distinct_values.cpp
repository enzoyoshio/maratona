#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
signed main() {
    cin.tie(0)->sync_with_stdio(false);
 
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto& it: v)
        cin >> it;
    
    set<int> s;
    map<int, int> freq;
    int ans = 0, r = 0;
 
    for(int l = 0; l < n; l++) {
        if(l > r) r = l;
        while(r < n) {
            s.insert(v[r]);
            freq[v[r]]++;
 
            if(s.size() > k) {
		freq[v[r]]--;
		if(!freq[v[r]])
			s.erase(v[r]);
		break;
	    }
	    r++;
        }
        
	/*
	cout << "elementos no set\n";
	for(auto el: s)
		cout << el << ' '; 
	cout << endl;
	cout << l << ' ' << r << endl;
	*/
        ans += r-l;
        int el = v[l];
        s.erase(el);
        freq[el]--;
        assert(freq[el] >= 0);
	/*
	cout << "element and freq of element\n";
	cout << el << ' ' << freq[el] << endl;
	*/
        if(freq[el])
            s.insert(el);

	/*
	cout << "elementos no set\n";
	for(auto it: s)
		cout << it << ' '; 
	cout << endl;
	*/
    }
 
    cout << ans << endl;
}
