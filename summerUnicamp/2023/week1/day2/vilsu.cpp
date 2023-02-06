#include <bits/stdc++.h>
using namespace std;

// Template (v1.3.1 - 2023-01-11) (codeforces:cebolinha, atcoder:edu) {{{

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#define int long long
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

template<class T> using V = vector<T>;
template<class T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;

#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define nemo ><>
#define loop(ii, n) for (int ii = 0; ii < (n); ii++)
#define xloop(ii, l, r) for (int ii = (l); ii <= (r); ii++)
#define cond(c, t, f) ((c) ? (t) : (f))
#define mem(a, b) memset((a), (b), sizeof(a))
#define inbounds(x, l, r) ((l) <= (x) && (x) <= (r))
#define L1(res...) [&](auto x){ return res; }
#define L2(res...) [&](auto x, auto y){ return res; }

template<class T, class U> inline void miq(T& a, U b){if (a > b) a = b;}
template<class T, class U> inline void maq(T& a, U b){if (a < b) a = b;}

template<class T> istream &operator>>(istream &is, vector<T> &v) { for (auto &a : v) is >> a; return is; }
template<class T, class U> ostream &operator<<(ostream &os, pair<T, U> const& p) { os << "(" << p.first << " " << p.second << ")"; return os; }
template<class T> ostream &operator<<(ostream &os, vector<T> const& v) { for (int i = 0; i < v.size(); i++) os << cond(i," ","") << v[i]; return os; }
template<class T, class U> ostream &operator<<(ostream &os, map<T, U> const& m) { bool first = true; for (auto const& [k, v] : m) { if (!first) os << " "; first = false; os << "{" << k << " : " << v << "}"; } return os; }
template<class T> ostream &operator<<(ostream &os, set<T> const& s) { for (auto it = s.begin(); it != s.end(); it++) os << cond(it != s.begin()," ","") << *it; return os; }

template<class... A> void in(A &...a) { ((cin >> a), ...); }
template<class... A> void out(A const&... a) { ((cout << a << " "), ...); cout << endl; }
template<class... A> void print(A const&... a) { ((cout << a), ...); }
#define var(x) "[", #x, " ", x, "] "
template<class... A> void db(A const&... a) { ((cout << (a)), ...); cout << endl; }
//}}}


const int D = 0, C = 1, E = 2, B = 3;


void printa(vector<vector<int>> &matriz, char c, bool swapped){

    int n = matriz.size(), m = matriz[0].size();

    if(swapped){
        loop(j, m){
            loop(i, n){
                if(matriz[i][j]) cout << c;
                else cout << ".";
            }
            cout << "\n";
        }
    }else{
        loop(i, n){
            loop(j, m){
                if(matriz[i][j]) cout << c;
                else cout << ".";
            }
            cout << "\n";
        }
    }
}






signed main(){

    int n, m; cin >> n >> m;
    bool swapped = (n > m);
    if(swapped) swap(n, m);

    vector<vector<int>> grid(n, vector<int>(m));
    if(swapped){
        loop(j, m){
            string s; cin >> s;
            loop(i, n) grid[i][j] = (s[i] == '2');
        }
    }else{
        loop(i, n){
            string s; cin >> s;
            loop(j, m) grid[i][j] = (s[j] == '2');
        }
    }

    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m)), c(n, vector<int>(m));


    if(n == 1){
        int l = 0, r = n-1;
        bool okl = false, okr = false;

        bool hastwo = false;
        loop(i, m) hastwo |= grid[0][i];

        if(!hastwo){
            if(m < 3) return cout << "impossible\n", 0;
            loop(i, m-2) a[0][i] = true;
            b[0][m-2] = true;
            c[0][m-1] = true;

            printa(a, 'A', swapped);
            cout << "\n";
            printa(b, 'B', swapped);
            cout << "\n";
            printa(c, 'C', swapped);

            return 0;
        }



        for(int i = 0; (i < m) && (!okl || grid[0][i]); i++){
            if(grid[0][i] && !okl){
                l = i;
                okl = true;
            }
            a[0][i] = true;
        }
        for(int i = m-1; (i >= 0) && (!okr || grid[0][i]); i--){
            if(grid[0][i] && !okr){
                r = i;
                okr = true;
            }
            b[0][i] = true;
        }

        xloop(i, l, r) c[0][i] = true;

        loop(i, m){
            if(grid[0][i] && (a[0][i]+b[0][i]+c[0][i] < 2)) return cout << "impossible\n", 0;
            if(!grid[0][i] && (a[0][i]+b[0][i]+c[0][i] != 1)) return cout << "impossible\n", 0;
        }

        printa(a, 'A', swapped);
        cout << "\n";
        printa(b, 'B', swapped);
        cout << "\n";
        printa(c, 'C', swapped);

        return 0;
    }


    if(n == 2){
        a[0][0] = true;
        a[1][0] = true;

        xloop(i, 1, m-1){
            b[0][i] = true;
            c[1][i] = true;

            if(grid[0][i]) c[0][i] = true;
            if(grid[1][i]) b[1][i] = true;
        }

        if(grid[0][0]) b[0][0] = true;
        if(grid[1][0]) c[1][0] = true;


        printa(a, 'A', swapped);
        cout << "\n";
        printa(b, 'B', swapped);
        cout << "\n";
        printa(c, 'C', swapped);

        return 0;
    }

    if(n == 3){

        loop(i, m){
            a[0][i] = true;
            b[1][i] = true;
            c[2][i] = true;

            if(grid[0][i]) b[0][i] = true;
            if(grid[1][i]) a[1][i] = true;
            if(grid[2][i]) b[2][i] = true;
        }

        printa(a, 'A', swapped);
        cout << "\n";
        printa(b, 'B', swapped);
        cout << "\n";
        printa(c, 'C', swapped);

        return 0;
    }


    if(n == 4){

        loop(i, m){
            a[0][i] = true;
            b[1][i] = true;
            b[2][i] = true;
            c[3][i] = true;

            if(grid[0][i]) b[0][i] = true;
            if(grid[1][i]) a[1][i] = true;
            if(grid[2][i]) c[2][i] = true;
            if(grid[3][i]) b[3][i] = true;
        }

        printa(a, 'A', swapped);
        cout << "\n";
        printa(b, 'B', swapped);
        cout << "\n";
        printa(c, 'C', swapped);

        return 0;
    }


    loop(i, n) a[i][0] = true;


    int x = n-2, y = 2, dir = D;

    while(true){

        b[x][y] = true;

        if(dir == D){

            if(((y+2 < m) && (b[x][y+2])) || (y+1 == m)){

                dir = C;
                x--;
                if(b[x][y] || b[x-1][y]) break;
            }else y++;
        }


        else if(dir == C){

            if((x-2 >= 0 && (b[x-2][y])) || (x-2 < 0)){
                dir = E;
                y--;

                if(b[x][y] || b[x][y-1]) break;
            }else x--;
        }


        else if(dir == E){

            if(a[x][y-2] || b[x][y-2]){


                dir = B;
                x++;

                if(b[x][y] || b[x+1][y]) break;
            }else y--;
        }


        else if(dir == B){

            if((x+2 < n && (b[x+2][y])) || (x+2 >= n)){
                dir = D;

                y++;
                if(b[x][y] || b[x][y+1]) break;
            }else x++;
        }
    }

    loop(i, n) loop(j, m) if(!a[i][j] && !b[i][j]) c[i][j] = true;

    loop(i, n){
        if(grid[i][0]) c[i][0] = true;
        if(grid[i][1]) a[i][1] = true;
    }

    loop(i, n) xloop(j, 2, m-1)
        if(grid[i][j]){
            if(b[i][j]) c[i][j] = true;
            else if(c[i][j]) b[i][j] = true;
        }

    printa(a, 'A', swapped);
    cout << "\n";
    printa(b, 'B', swapped);
    cout << "\n";
    printa(c, 'C', swapped);

    return 0;
}
