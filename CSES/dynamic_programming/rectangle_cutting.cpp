#include <bits/stdc++.h>

using namespace std;

int a, b;

int tb[550][550];

int dp(int w, int h) {

	if(w == h) 
		return 0;

	auto& ans = tb[w][h];

	if(~ans)
		return ans;

	ans = 1000000;

	for(int i = 1; i < w; i++) {
		ans = min(ans, 1 + dp(i, h) + dp(w-i, h));
	}

	for(int i = 1; i < h; i++)
		ans = min(ans, 1 + dp(w, i) + dp(w, h-i));

	return ans;

}

int main() {
	memset(tb, -1, sizeof tb);
	cin >> a >> b;

	for(int i = 0; i < 550; i++)
		tb[i][i] = 0;

	for(int w = 1; w <= a; w++) {
		for(int h = 1; h <= b; h++) {
			if(w == h) continue;

			auto& ans = tb[w][h];
			ans = 10000000;

			for(int i = 1; i < w; i++)
				ans = min(ans, 1 + tb[i][h] + tb[w-i][h]);

			for(int i = 1; i < h; i++)
				ans = min(ans, 1 + tb[w][i] + tb[w][h-i]);

		}
	}

	cout << tb[a][b] << endl;
}
