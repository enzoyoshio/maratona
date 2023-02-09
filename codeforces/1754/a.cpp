#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t; while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        vector<int> qt(n, 0);
        for(int i = 0; i < n; i++)
            if(s[i] == 'A')
                qt[i] = 1;
        for(int i = 1; i < n; i++) {
            qt[i] += qt[i-1];
        }

        bool can = 1;
        int per = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'Q') per++;
            if(s[i] == 'Q' && qt[i] < per) can = 0; 
        }

        cout << (!can ? "No" : "Yes") << endl;
    }
}
