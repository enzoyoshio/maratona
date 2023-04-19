#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
using tiiii = tuple<int,int,int,int>;
 
vector<int> v;
  
int query(int l, int r) {
  if(l == 0) return v[r];
  return v[r] - v[l-1];
}
 
signed main() {
	cin.tie(0)->sync_with_stdio(false);
  
  	int n, k;
  	cin >> n >> k;
  	v.resize(n);
  	for(auto& it: v)
      	cin >> it;
  	for(int i = 1; i < n; i++)
		v[i] += v[i-1];
 
  	set<tiiii> s;
	s.emplace(v.back(), n, 0, n-1);
  
  	while((int)s.size() < k) {

		auto p = prev(s.end());
		s.erase(prev(s.end()));
		
		auto [valor, tamanho, left, right] = *p;
		
		int mid = valor/2;
		auto proc = upper_bound(v.begin(), v.end(), mid + (left ? v[left-1] : 0));
		int idx = proc - v.begin();
		//cout << valor << ' ' << left << ' ' << right << ' ' << tamanho << endl;
		//cout << idx << endl;
	      
		if(idx == right) {
			s.emplace(-query(right, right), 1, right, right);
			s.emplace(query(left, right-1), tamanho-1, left, right-1);
		}else if(idx == left) {
			s.emplace(-query(left, left), 1, left, left);
			s.emplace(query(left+1, right), tamanho-1, left+1, right);
		}else {
		  if(idx-left+1 == 1)
		      s.emplace(-query(left, idx), idx-left+1, left, idx);
		  else 
		      s.emplace(query(left, idx), idx-left+1, left, idx);
		  if(right-idx == 1) 
		      s.emplace(-query(idx+1, right), right-idx, idx+1, right);
		  else 
		      s.emplace(query(idx+1, right), right-idx, idx+1, right);
		}
	}
    
  	cout << max(abs(get<0>(*s.rbegin())), abs(get<0>(*s.begin())) ) << endl;
}
