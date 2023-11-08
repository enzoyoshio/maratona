#include <bits/stdc++.h>
using namespace std;
//alias comp='g++ -std=c++17 -g -O2 -Wall -Wconversion -Wshadow -fsanitize=address,undefined -fno-sanitize-recover -ggdb -o out'
//
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define endl "\n"
#define input(x) for (auto &it : x) cin >> it
#define pb push_back
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define TETO(a, b) ((a) + (b-1))/(b)
#define dbg(msg, x) cout << msg << " = " << x << endl
#define print(x,y) for (auto &it : x) cout << it

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
typedef priority_queue<int, vector<int>, greater<int>> pqi;

const ll MOD = 1e9+7;
const int MAX = 2e6+5;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
int32_t main(){ sws; 
    int n, m; cin>>n>>m;

        if(m == 1){
                cout<<1<<" "<<2<<endl;
                        return 0;
                            }

//                                // m = 3
//                                    // 1 2 3 4 5 6 7
//                                        // 1 
                                            int count = m-1;
                                                int l=1, r=m+1;
                                                    for(int i=1; i<=m/2; i++){
                                                            cout<<l<<" "<<l+count<<endl;
                                                                    l++;
                                                                            count-=2;
                                                                                }
                                                                                    count = m;
                                                                                        for(int i=1; i<=TETO(m, 2); i++){
                                                                                                cout<<r<<" "<<r+count<<endl;
                                                                                                        r++;
                                                                                                                count-=2;
                                                                                                                    }

                                                                                                                        return 0;
                                                                                                                        }
