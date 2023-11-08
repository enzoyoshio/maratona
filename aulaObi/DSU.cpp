#include <bits/stdc++.h>

using namesapce std;

struct DSU {
  vector<int> cor, tam;
  int n;

  DSU(int _n) : n(_n), cor(_n), tam(_n, 1) {
    for(int i = 0; i < n; i++)
      cor[i] = i;
  }

  int find_color(int x) {
    if(cor[x] == x) return x;

    cor[x] = find_color(cor[x]);
    return cor[x];
  }
  
  // same_set
  bool same_set(int x, int y) {
    return find_color(x) == find_color(y);
  }

  void merge_set(int x, int y) {
    if(same_set(x, y)) return;

    int corX = find_color(x);
    int corY = find_color(y);

    if(tam[corX] < tam[corY]) {
      cor[corX] = corY;
      tam[corY] += tam[corX];
    }else {
      cor[corY] = corX;
      tam[corX] += tam[corY];
    }

    /*
       if(tam[corX] < tam[corY]) swap(corX, corY);
       cor[corY] = corX;
       tam[corX] += tam[corY];
    */
  }

};

int main() {

}
