#include <bits/stdc++.h>

#define int long long
#define dbg(msg,x) cerr<<msg<<": "<<x<<endl;
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

const int MAXN = 3e5;

int trie[2][MAXN];
int cur_idx=1;

void add(int cur_number, int bit=32, int id=0) {

    if(bit == 0) return;

    int turn = ((1 << (bit-1)) & cur_number);

    if(turn) {
        if(trie[1][id] == -1) {
            trie[1][id] = cur_idx++;
        }
        add(cur_number, bit-1, trie[1][id]);
    }else {
        if(trie[0][id] == -1) {
            trie[0][id] = cur_idx++;
        }
        add(cur_number, bit-1, trie[0][id]);
    }
}

int search(int cur, int bit=32, int id=0, int val=0) {

    if(bit == 0) return val;

    int turn = ((1 << (bit-1)) & cur);

    if(turn) {
        if(trie[1][id] == -1) {
            return search(cur, bit-1, trie[0][id], 0) + (val << (bit));
        }else {
            return search(cur, bit-1, trie[1][id], 1) + (val << (bit));
        }
    }else {
        if(trie[0][id] == -1) {
            return search(cur, bit-1, trie[1][id], 1) + (val << (bit));
        }else {
            return search(cur, bit-1, trie[0][id], 0) + (val << (bit));
        }

    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    for(int i= 0; i < MAXN; i++) trie[0][i] = trie[1][i] = -1;

    int n;cin>>n;

    int total =0;

    rep(i,0,n){
        int x;
        cin>>x;
        total^=x;
        add(x);
        int k = search(total);      
        cout<<(total^k)<<endl;
    }


}