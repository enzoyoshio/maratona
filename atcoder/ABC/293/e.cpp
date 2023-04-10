#include <bits/stdc++.h>

using namespace std;

int a, m;
long long x;

int add(int a, int b) {
	return (a+b)%m;
}

int sub(int a, int b) {
	return ((a-b)%m + m)%m;
}

int mul(int a, int b) {
	return ((long long)a * (long long)b)%m;
}

int fexp(int b, long long e=m-2) {
	if(e == 0) return 1;

	int x = fexp(b, e/2);
       	x = mul(x, x);

	if(e%2) x = mul(x, b);
	
	return x;	
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> a >> x >> m;

	cout << add(mul(mul(a, sub(fexp(a, x-1), 1)), fexp(a-1)), 1) << endl;
}
