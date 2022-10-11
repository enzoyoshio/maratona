#include<bits/stdc++.h>
using namespace std;

#define int long long

int small(multiset<int> &S) {
  return *(S.begin());
}
int big(multiset<int> &S) {
  return *(S.rbegin());
}
void erase_one(multiset<int> &S, int x) {
  S.erase(S.find(x));
}

signed main(){
    // LE TUDO
    int n; cin >> n;
    vector<int> cima, baixo;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        cima.push_back(x);
    }
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        baixo.push_back(x);
    }
    int k, l; cin >> k >> l;

    int ans = 0;
    int somaCima = 0;
    int somaMelhores = 0;
    multiset<int> LMelhores, resto;

    // adicionar k iniciais
    for(int i = 0; i < k; i++){
      somaCima += cima[i];
      if (LMelhores.size() < l) { // ainda nao ta cheio
        LMelhores.insert(baixo[i]); somaMelhores += baixo[i];
      } else if (small(LMelhores) < baixo[i]) { // e pra adicionar
        int s = small(LMelhores);
        resto.insert(s);
        erase_one(LMelhores, s); somaMelhores -= s;
        LMelhores.insert(baixo[i]); somaMelhores += baixo[i];
      } else { // fica no resto
        resto.insert(baixo[i]);
      }
    }
    ans = somaCima + somaMelhores;

    for (int i = 1; i <= k; i++) {
      // remove guy
      int removeIdx = k-i;
      if (baixo[removeIdx] >= small(LMelhores)) { // ta nos maiores
        erase_one(LMelhores, baixo[removeIdx]); somaMelhores -= baixo[removeIdx];
        if (resto.size()) {
          int b = big(resto);
          erase_one(resto, b);
          LMelhores.insert(b); somaMelhores += b;
        }
      } else {
        erase_one(resto, baixo[removeIdx]);
      }

      int addIdx = n-i;
      if (LMelhores.size() < l) LMelhores.insert(baixo[addIdx]); // nao ta cheio
      else if (baixo[addIdx] > small(LMelhores)) { // merece estar nos maiores
        LMelhores.insert(baixo[addIdx]); somaMelhores += baixo[addIdx];
        int s = small(LMelhores);
        erase_one(LMelhores, s); somaMelhores -= s;
        resto.insert(s);
      } else { // vai pro test
        resto.insert(baixo[addIdx]);
      }

      somaCima += cima[addIdx]; somaCima -= cima[removeIdx];
      ans = max(ans, somaCima+somaMelhores);
    }

    cout << ans << endl;
}
