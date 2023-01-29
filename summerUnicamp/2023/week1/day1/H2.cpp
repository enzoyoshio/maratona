#include <bits/stdc++.h>

using namespace std;

#define no cout << "impossible\n"
using ull = unsigned long long;

unordered_map<ull,bool> tb;

ull mix(ull o){
    o+=0x9e3779b97f4a7c15;
    o=(o^(o>>30))*0xbf58476d1ce4e5b9;
    o=(o^(o>>27))*0x94d049bb133111eb;
    return o^(o>>31);
    //Those constants supposedly are chosen to give this function better pseudo-random properties, but on any on-site contest, when one can't have team reference document/doesn't want to waste time searching it for implementation typing arbitrary large odd numbers by hand should be good enough
}

map<tuple<int,int,vector<int>>, bool> dp;

bool can(int wide, int left, vector<int>& qtd, int assentosLivres, int pessoas) {
    
    int x = mix(wide ^ mix(left));

    for(auto el: qtd) x = mix(x ^ mix(el));

    if(tb.find(x) != tb.end()) return tb[x];

    // if(dp.find({wide, left, qtd}) != dp.end()) return dp[{wide, left, qtd}];

    if(*max_element(qtd.begin(), qtd.end()) == 0) return true;
    
    if(wide < 1) return false;

    if(left <= 0) 
        return can(wide-1, left=wide-1, qtd, assentosLivres, pessoas);

    bool ans = false;
    for(int i = 0; !ans && i < 12; i++) {
       if(left >= i+1 && i < qtd.size() && qtd[i] > 0) {
           qtd[i]--;
//           cout << "to aqui " << wide << ' ' << left << endl;
            if(left-(i+1) >= 0)
           bool aux = can(wide, left-(i+2), qtd);
 //           cout << "Meu filho conseguiu ? " << aux << endl;
  //          cout << "i = " << i << endl;
           ans |= aux; 
           qtd[i]++;
       } 
    }

    return tb[x] = ans;
    return dp[{wide, left, qtd}] = ans;
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, total = 0;
    cin >> n;
    vector<int> v(n);
    vector<int> value = {30, 26, 18, 13, 10, 7, 6, 5, 4, 3, 2, 1};
    for(auto& it: v) cin >> it;
    for(int i = 0; i < n; i++)
        total += (i+1)*v[i];

    for(int i = 12; i > 0; i--) {
        if(n >= i && v[i-1] > value[i-1]) return no, 0;
    }

    for(int i = 1; i <= 12; i++) {
        if(can(i, i, v, i*(i+1)/2, total)) return cout << i << endl, 0;
    } 

    no;

}


