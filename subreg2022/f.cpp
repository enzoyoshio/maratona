#include <bits/stdc++.h>
using namespace std; 

#define int unsigned long long

const int MCHAR = 27;

map<int, int> M;
int n, c;

void add(string &s) {
  bool pastAst = false;
  int single = 0;
  vector<int> hashes;
  for (int ci = 0; ci < c; ci++) {
    if (s[ci] == '*') {
      for (int i = 1; i <= MCHAR; i++) {
        pastAst = true;
        hashes.push_back(single*MCHAR + i);
      }
    } else {
      if (pastAst) {
        for (auto &h : hashes) {
          h *= MCHAR; h += s[ci]-'a' + 1;
        }
      } else {
        single *= MCHAR; single += s[ci]-'a' + 1;
      }
    }
  }
  for (auto h : hashes) M[h]++;
}

string decode(int x) {
  string ans = "";
  while (x) {
    ans += 'a' + (x % MCHAR) - 1;
    x /= MCHAR;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> c;
  for (int i = 0; i < n; i++) {
    int astPos = 0;
    string s; cin >> s;
    add(s);
  }

  int best = 0;
  int ans = 0;
  for (auto &[k, v] : M) {
    if (v > best) best = v, ans = k;
    if (v == best) ans = min(ans, k);
  }
  cout << decode(ans) << " " << best <<  endl;
}
