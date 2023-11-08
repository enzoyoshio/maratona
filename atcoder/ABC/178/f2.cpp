#include <bits/stdc++.h>

using namespace std;

int main() {
cin.tie(0)->sync_with_stdio(false);

int n;
cin >> n;
vector<int> a(n), b(n), fa(n), fb(n);

for(auto& it: a) cin >> it, it--, fa[it]++;
for(auto& it: b) cin >> it, it--, fb[it]++;

for(int i = 0; i < n; i++)
if(fa[i] + fb[i] > n)
return cout << "No\n", 0;	

vector<int> ans(n);
		set<pair<int,int>> sb;
				for(int i = 0; i < n; i++) {
							sb.insert({fb[i], i});
								}

					for(int i = 0; i < n; i++) {
								auto& [qt, id] = *prev(end(sb));
										if(id == a[i]) {
														if(sb.size() < 2) return cout << "No\n", 0;
																	auto [qt1, id1] = *prev(prev(end(sb)));
																				ans[i] = id1+1;
																							sb.erase({qt1, id1});
																										if(qt1-1)
																															sb.insert({qt1-1, id1});
																												}else {
																																ans[i] = id+1;
																																			sb.erase({qt, id});
																																						if(qt-1)
																																											sb.insert({qt-1, id});
																																								}
											}

						cout << "Yes\n";
//							for(auto el: ans) cout << el << ' ';
//								cout << endl;
}
