#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	long long a, b;
	cin >> a >> b;
	long long ans = 0;

	while(a != b && a && b) {
		if(b > a) swap(a, b);
		ans += a/b;
		if(a%b == 0) ans--, a = b;
		else a %= b;
	}

	cout << ans << endl;
}
