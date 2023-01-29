#include <bits/stdc++.h>

using namespace std;

#define A 0
#define B 1
#define C 2

int n, m;
void print(vector<vector<int>>& v, int swapped) {

    if(swapped) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                cout << v[j][i] << ' ' ;
            cout << endl;
        }
    }else {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                cout << v[i][j] << ' ';
            cout << endl;
        }
    }
}

void print_color(vector<vector<int>>& v, char c, bool swapped) {
 
    if(swapped) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(v[j][i]) cout << c;
                else cout << '.';
            }
            cout << endl;
        }
    }else {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(v[i][j]) cout << c;
                else cout << '.';
            }
            cout << endl;
        }
    }
   
}

void no() {
    cout << "impossible\n";
}

bool bounded(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    vector<string> ler(n);
    vector<vector<int>> v(n, vector<int>(m));

    for(auto& line: ler) cin >> line;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            v[i][j] = ler[i][j]-'0';

    bool swapped = false;
    
    if(n > m) {
        swapped = 1;
        swap(n, m);
        vector<vector<int>> v1(n, vector<int>(m));
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++)
                v1[i][j] = v[j][i];
        v = v1;
    }

    vector<vector<vector<int>>> color(3, vector<vector<int>>(n, vector<int>(m, 0)));

    if(n == 1) {

        int cur = 0;
        for(int i = 0; i < m; i++) {
            color[A][0][i] = 1;
            if(v[0][i] == 2) {
                if(i == 0 || v[0][i-1] == 1) cur++;
                if(cur > 2) return no(), 0;
                color[cur][0][i] = 1;
            }
        }

        // se nao tem 2
        if(cur == 0) {
            if(m < 3) return no(), 0;
            color[B][0][0] = 1;
            color[A][0][0] = color[A][0][1] = 0;
            color[C][0][1] = 1;
        }else if(cur == 1) {
            // se so tem um range 2

            for(int i = 0; i < m; i++) {
                if(v[0][i] == 2) {
                    color[C][0][i] = 1;
                    break;
                }
            }
        }

        print_color(color[A], 'A', swapped);
        cout << endl;
        print_color(color[B], 'B', swapped);
        cout << endl;
        print_color(color[C], 'C', swapped);
        return 0;
    }

    if(n == 2) {

        color[A][0][0] = 1;
        color[A][1][0] = 1;
        for(int i = 1; i < m; i++) {
            color[B][0][i] = 1;
            color[C][1][i] = 1;
        }

        for(int i = 0; i < m; i++) {
            for(int corzinha = 0; corzinha < 2; corzinha++) {
                if(v[corzinha][i] == 2) {
                    if(i == 0) {
                        color[corzinha+1][corzinha][i] = 1;
                    }else {
                        color[3-(corzinha+1)][corzinha][i] = 1;
                    }
                }
            }
        }

        print_color(color[A], 'A', swapped);
        cout << endl;
        print_color(color[B], 'B', swapped);
        cout << endl;
        print_color(color[C], 'C', swapped);
               
        return 0;
    }

    if(n == 3) {

        for(int i = 0; i < m; i++) {
            for(int corzinha = 0; corzinha < 3; corzinha++) {
                color[corzinha][corzinha][i] = 1;
            }
        }

        for(int i = 0; i < m; i++) {
            for(int cor = 0; cor < 3; cor++) {
                if(v[cor][i] == 2) {
                    if(cor == 1) {
                        color[A][1][i] = 1;
                    }else {
                        color[B][cor][i] = 1;
                    }
                }
            }
        }

        print_color(color[A], 'A', swapped);
        cout << endl;
        print_color(color[B], 'B', swapped);
        cout << endl;
        print_color(color[C], 'C', swapped);
               

        return 0;
    }

    if(n == 4) {
 
        for(int i = 0; i < m; i++) {
            color[A][0][i] = 1;
            color[B][1][i] = 1;
            color[B][2][i] = 1;
            color[C][3][i] = 1;
        }

        for(int i = 0; i < m; i++) {
            if(v[0][i] == 2) {
                color[B][0][i] = 1;
            }

            if(v[1][i] == 2) {
                color[A][1][i] = 1;
            }
            if(v[2][i] == 2) {
                color[C][2][i] = 1;
            }
            if(v[3][i] == 2) {
                color[B][3][i] = 1;
            }
        }

        print_color(color[A], 'A', swapped);
        cout << endl;
        print_color(color[B], 'B', swapped);
        cout << endl;
        print_color(color[C], 'C', swapped);
       
        return 0;
    }

    if(n == 5) {
        // pintando a parte esquerda
        for(int i = 0; i < n; i++) {
            color[A][i][0] = 1;
            if(i && i+1 < n) color[B][i].back() = 1;
        }

        for(int j = 2; j < m; j++) color[B][1][j] = 1;
        for(int j = 2; j < m; j++) color[B][n-2][j] = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!color[A][i][j] && !color[B][i][j]) color[C][i][j] = 1;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(v[i][j] == 2) {
                    if(j == 0) color[C][i][j] = 1;
                    else if(j == 1) color[A][i][j] = 1;
                    else color[B][i][j] = color[C][i][j] = 1;

                }
            }
        }

        print_color(color[A], 'A', swapped);
        cout << endl;
        print_color(color[B], 'B', swapped);
        cout << endl;
        print_color(color[C], 'C', swapped);
 
        return 0;
    }

    // pintando a parte esquerda
    for(int i = 0; i < n; i++) {
        color[A][i][0] = 1;
    }

    pair<int,int> dir(0, 1);
    int posx = n-2, posy = 2;

    while(true) {

        /*
        cout << "\n\nto na posicao " << posx << ' ' << posy << endl;
        print_color(color[B], 'B', swapped);
        */
        if(color[B][posx][posy]) break;
        color[B][posx][posy] = 1;

        if(bounded(posx-1, posy) && bounded(posx+1, posy) && bounded(posx, posy+1) && bounded(posx, posy-1) && 
                (
                (color[B][posx][posy+1] != color[B][posx+1][posy] && color[B][posx][posy+1] == color[B][posx][posy-1] && color[B][posx-1][posy] == color[B][posx+1][posy])
                //||
                //(color[B][posx][posy+1] == color[B][posx][posy-1] && color[B][posx-1][posy] == color[B][posx+1][posy])
                )
                ) {
            color[B][posx][posy] = 0;
            break;
        }

        // indo para direita
        if(dir.first == 0 && dir.second == 1) {
            //cout << "to indo para direita\n";
            // se eu chegar na parede, virar para cima
            // ou o vizinho do vizinho ja ta colorido
            if(!bounded(posx + dir.first, posy + dir.second)
                    ||
                    (posy + 2 < m && color[B][posx][posy+2] == 1)) {
                dir.first = -1, dir.second = 0;
               
            }

            posx += dir.first, posy += dir.second;
        }else if(dir.first == -1 && dir.second == 0) {
            //cout << "to indo para cima\n";
            // indo para cima
            if(!bounded(posx + 2*dir.first, posy + 2*dir.second) || 
                color[B][posx + 2*dir.first][posy + 2*dir.second]
              ) {
                dir.first = 0, dir.second = -1;
            }

            posx += dir.first, posy += dir.second;
        }else if(dir.first == 0 && dir.second == -1) {
            //cout << "to indo para esquerda\n";
            // indo para esquerda
            if(color[A][posx + 2*dir.first][posy + 2*dir.second] ||
                color[B][posx + 2*dir.first][posy + 2*dir.second]
              ) {
                dir.first = 1, dir.second = 0;
            }
            
            posx += dir.first, posy += dir.second;
        }else if(dir.first == 1 && dir.second == 0) {
            //cout << "to indo para baixo\n";
            // indo para baixo 
            if(color[B][posx + 2*dir.first][posy + 2*dir.second]) 
                dir.first = 0, dir.second = 1;

            posx += dir.first, posy += dir.second;
        }
    }    

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!color[A][i][j] && !color[B][i][j]) color[C][i][j] = 1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == 2) {
                if(j == 0) color[C][i][j] = 1;
                else if(j == 1) color[A][i][j] = 1;
                else color[B][i][j] = color[C][i][j] = 1;

            }
        }
    }

    print_color(color[A], 'A', swapped);
    cout << endl;
    print_color(color[B], 'B', swapped);
    cout << endl;
    print_color(color[C], 'C', swapped);
 
}

/*
 
5 5
ACCCC
ACBBB
ACCCB
ACBBB
ACCCC

6 6
ACCCCC
ACBBBB
ACBBCB
ACCCCB
ACBBBB
ACCCCC
 */
