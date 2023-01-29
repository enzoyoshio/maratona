#include <bits/stdc++.h>

using namespace std;

int W = 0, B = 1;

int main() {
    int a, b;
    cin >> a >> b;
    
    bool swapped = false;
    int menor = B, maior = W;
    if(a < b) swap(a, b), swapped = true, swap(menor, maior);

    vector<vector<int>> v(100, vector<int>(100, maior));

    if(a == 1 && b == 1) {
        cout << 1 << ' ' << 2 << endl;
        cout << ".#" << endl;
        return 0;
    }

    int last = 0;
    a--;
    b--;
    for(int i = 1; a > 0 && i < 100; i+=2) {
        for(int j = 0; j < 100; j++) v[i][j] = menor;

        if(a >= 50) {
            a -= 50;
            for(int j = 1; j < 100; j+= 2) v[i-1][j] = menor;
        }else {
//            cout << "to aqui\n?";
            a--;
            if(a == 0) b--;
            for(int j = 1; a > 0 && j < 100; j += 2) a--, v[i-1][j] = menor;
        }
        last = i+2;
    }


    for(int i = last;b > 0 && i < 100; i+= 2) {
        for(int j = 0; b > 0 && j < 100; j+= 2) {
            b--, v[i][j] = menor;
        }
    }

    cout << 100 << ' ' << 100 << endl;
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(v[i][j] == B) cout << ('#');
            else            cout << ('.');
        }
        cout << endl;
    }
}
