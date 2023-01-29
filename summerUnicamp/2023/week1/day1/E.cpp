#include <bits/stdc++.h>

using namespace std;

vector<int> z_algo(const string& s) {
    int n = s.size();
    int L = 0, R = 0;
    vector<int> z(n, 0);

    for(int i = 1; i < n; i++) {
        if(i <= R) 
            z[i] = min(z[i-L], R-i+1);
        while(z[i]+i < n && s[ z[i] + i ] == s[z[i]])
            z[i]++;
        if(i+z[i]-1 > R) {
            L = i;
            R = i + z[i] -1;
        }
    }

    return z;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    string pat;
    int n;
    cin >> pat >> n;

    string pref = "";
    while(pat.size() && *pat.begin() != '*') pref += *pat.begin(), pat.erase(pat.begin());

    string suf = "";
   while(pat.size() && *pat.rbegin() != '*') suf += pat.back(), pat.pop_back();
    reverse(suf.begin(), suf.end());
    
    vector<string> pp;
    for(int i = 0; i < pat.size(); i++) {
        if(pat[i] != '*') {
            string getS = "";
            while(i < pat.size() && pat[i] != '*') getS += pat[i++];
            pp.push_back(getS); 
        }
    }

    for(int i = 0; i < n; i++) {
        string cur; cin >> cur;
        string original = cur;

        if(pat == "") {
            if(cur == pref) cout << cur << endl;
        }else {
            bool eq=true;
            for(int i = (int)suf.size()-1; eq && i >= 0; i--) {
                if(cur.empty() || suf[i] != cur.back()) eq = false;
                cur.pop_back();
            }

            
            for(int i = 0; eq && i < pref.size(); i++) {
                if(cur.empty() || pref[i] != *cur.begin()) eq = false;
                cur.erase(cur.begin());
            }

            if(!eq) continue;

            string ajuda;
            int idx = -1;
            for(int i = 0; i < pp.size() && eq; i++) {
                ajuda = pp[i] + '#' + cur;
                auto zfuncs = z_algo(ajuda);
                
                /*
                cout << original << endl;
                cout << ajuda << endl;
                for(auto it: zfuncs) cout << it << ' '; cout << endl;
                */

                bool achou = false;
                // cout << "\n\ntamano do pp " << pp[i].size() << endl;
                for(int j = pp[i].size(); !achou && j < ajuda.size(); j++) { 
                    /*
                    cout << "\n\ndebug zfuncs[j] =" << zfuncs[j] << endl;
                    cout << "idx = " << idx << endl;
                    cout << "j = " << j << endl;
                    cout << "j - (pp[i].size()+1) = " << j - ((int)pp[i].size()+1) << endl;
                    cout << "zfuncs[j] == pp[i].size() ? " << (zfuncs[j] == pp[i].size()) << endl;
                    cout << (idx < (int)(j-(pp[i].size()+1))) << endl;
                    */

                   if(zfuncs[j] == (int)pp[i].size() && idx < j-((int)pp[i].size()+1)) {
//                       cout << "entrei no if " << pp[i].size() << endl;
                        idx = j-((int)pp[i].size())-1;
                        achou = true;
                   }
                }

                if(!achou) eq = false;
            }

            if(!eq) continue;

            cout << original << endl; 
            
       }
    }

}
