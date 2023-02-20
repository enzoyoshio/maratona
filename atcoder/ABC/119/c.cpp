#include <bits/stdc++.h>

using namespace std;

const int oo = 1e8;
int n, a, b, c;
vector<int> bamboo;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> a >> b >> c;
    bamboo.assign(n, 0);
    for(auto& it: bamboo) cin >> it;

    int ans = oo;
    for(int bit = 0; bit < (1 << 2*n); bit++) {
        bitset<20> bits(bit);
        int aa = a, bb = b, cc = c;
        int takena = 0, takenb = 0, takenc = 0;
        for(int i = 0; i < 2*n; i += 2) {
            int num = bits[i]*10 + bits[i+1]; 
            if(num == 0) {
                aa -= bamboo[i/2]; 
                takena++;
            }else if(num == 1) {
                bb -= bamboo[i/2];
                takenb++;
            }else if(num == 10) {
                cc -= bamboo[i/2];
                takenc++;        
            }
            //cout << bits.to_string() << endl;
        }        
       
        ans = min(ans, (takena ? (takena -1) *10 : oo) + (takenb ? (takenb -1)*10 : oo) + (takenc ? (takenc -1)*10 : oo) + abs(aa) + abs(bb) + abs(cc));
    }
    cout << ans << endl;

}
