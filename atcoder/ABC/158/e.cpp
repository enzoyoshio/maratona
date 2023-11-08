#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, p; 
string s;

int mul(int a, int b) { return (a*b)%p;}
int add(int a, int b) { return (a+b)%p;}
int sub(int a, int b) { return ((a-b)%p+p)%p;}
int fexp(int b, int e=p-2) {
    if(e == 0) return 1LL;
    int x = fexp(b, e/2);
    x = mul(x, x);
    if(e%2) x = mul(x, b);
    return x;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> p >> s;
    int ans = 0;

    if(p == 2) {
      for(int i = 0; i < n; i++)
        if((s[i]-'0')%2 == 0) ans += i+1;
      return cout << ans << endl, 0;
    }else if(p == 5) {
      for(int i = 0; i < n; i++)
        if((s[i]-'0')%5 == 0) ans += i+1;
      return cout << ans << endl, 0;
    }

    reverse(s.begin(), s.end());
    vector<int> psum(n);
    map<int,int> lembra;
    map<int,int> both;
    lembra[0] = 1;
    int dez = 0;
    for(int i = 0; i < n; i++) {
	psum[i] = mul(s[i]-'0', fexp(10, i));
	if(i) psum[i] = add(psum[i], psum[i-1]);

	ans += lembra[psum[i]];
	lembra[psum[i]]++;
    }
    cout << ans << endl;
}

