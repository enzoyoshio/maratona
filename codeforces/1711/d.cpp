#include <bits/stdc++.h>

using namespace std;

#define int long long

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"

// st[i].first = soma de chuva na regiao (l, r)
// st[i].second = qt de pontos na regiao (l, r)

const int oo = 1e17;
const int MAXN = 2e5+8;
using tiii = tuple<int,int,int>;

struct ST {
  vector<pair<int,int>> st;
  int n;

  ST(int n) : n(n) {
    st.assign(4*n, pair<int,int>(0,0));
  }

  pair<int,int> merge(pair<int,int> a, pair<int,int> b) {
    a.first += b.first;
    a.second += b.second;
    return a;
  }

  pair<int,int> update(int id, pair<int,int> x, int sti, int stl, int str) {
    if(str < id || stl > id) return st[sti];
    if(stl == str) return st[sti] = merge(st[sti], x);
    int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;
    return st[sti] = merge(update(id, x, ste, stl, stm), update(id, x, std, stm+1, str));
  }

  pair<int,int> query(int l, int r, int sti, int stl, int str) {
    if(l > str || stl > r) return pair<int,int>(0,0);
    if(l <= stl && str <= r) return st[sti];
    int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;
    auto qry1 = query(l, r, ste, stl, stm);
    auto qry2 = query(l, r, std, stm+1, str);
    return merge(qry1, qry2);
  }

  pair<int,int> update(int id, pair<int,int> x) {
    return update(id, x, 1, 0, n-1);
  }

  pair<int,int> query(int l, int r) {
    if(r < l) return {0, 0};
    return query(l, r, 1, 0, n-1);
  }
};

int id(int a, vector<int>& ord) {
  return lower_bound(begin(ord), end(ord), a) - begin(ord);
}

int idUp(int a, vector<int>& ord) {
  return upper_bound(begin(ord), end(ord), a) - begin(ord);
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
    int n, m, qt = 0;
		cin >> n >> m;
		vector<tiii> v(n);
    map<int,vector<int>> rains;
    for(int i = 0; i < n; i++) {
      auto& [a, b, c] = v[i];
      cin >> a >> b; c = i;
      rains[a].emplace_back(b);
    }

    sort(begin(v), end(v));

    set<int> posis;
    for(auto [a, b, c]: v)
      posis.insert(a);

    // vector que fala a posicao de cada cara
    vector<int> pos;
    for(auto el: posis)
      pos.push_back(el);
    vector<int> level((int)pos.size());
    vector<int> ord;

    for(int i = 0; i < n; i++) {
      auto [xi, pi, idx] = v[i];
      posis.insert(xi-pi);
      posis.insert(pi+xi);
    }
    for(auto el:posis)
      ord.push_back(el);

    sort(begin(ord), end(ord));
    ST stGreater(ord.size()), stLess(ord.size());

    for(int i = 0; i < n; i++) {
      auto [xi, pi, idx] = v[i];
      /*
      db(xi);
      db(pi);
      db(xi-pi);
      */
      stGreater.update(id(xi-pi, ord), pair<int,int>(xi-pi, 1));
      /*
      auto [val, qt] = stGreater.query(id(xi-pi, ord), id(xi-pi, ord));
      db(val);
      db(qt);
      */
    }

    for(auto [xi, vec]: rains) {
      //cerr << "\n-------------------------- db -------------------\n";
      vector<int> upd;
      int idx = id(xi, pos);
      for(auto pi: vec) {
      /*  
        db(xi);
        db(pi);
        db(xi-pi);
        */
        stGreater.update(id(xi-pi, ord), {-(xi-pi), -1});
        upd.push_back(xi+pi); 
        level[idx] += pi;
      }

      auto [rightSum, rightQt] = stGreater.query(0, id(xi, ord)-1);
      auto [leftSum, leftQt] = stLess.query(idUp(xi, ord), stLess.n-1);

      /*
      db(id(xi, ord));
      db(id(4, ord));
      auto [val, qt] = stGreater.query(id(4, ord), id(4, ord));
      db(val);
      db(qt);

      db(xi);
      db(rightSum);
      db(rightQt);
      db(leftSum);
      db(leftQt);
// se xi > xj
// pi - (xi - xj) > 0
// pi - xi + xj > 0
//                     -> pi - xi > -xj
//                     -> xi - pi < xj
// se xi < xj
// pi - (xj - xi) > 0
// pi - xj + xi > 0
// pi + xi - xj > 0
//                     -> pi + xi > xj
      db(level[idx]);
//                     */

      level[idx] += leftSum - xi*leftQt;
      level[idx] += -rightSum + xi*rightQt;

      for(auto att: upd) {
        stLess.update(id(att, ord), {att, 1});
      }
    }

    int last, first = -1;
    int l = -oo, r = -oo;
    vector<int> fromLeft(pos.size(), -oo), fromRight(pos.size(), -oo);
    for(int i = 0; i < (int)pos.size(); i++) {
      if(level[i] <= m) continue;
      /*
      db(r);
      db(level[i] - m - pos[i]);
      db(pos[i]);
      */
      r = max(r, level[i] - m - pos[i]);
      
      fromLeft[i] = r;
    }

    for(int i = (int)pos.size()-1; i >= 0; i--) {
      if(level[i] <= m) continue;
      /*
      db(l);
      db(level[i] - m + pos[i]);
      db(pos[i]);
      */
      l = max(level[i] - m + pos[i], l);
      fromRight[i] = l;
    }

   for(int i = 1; i < pos.size(); i++)
      fromLeft[i] = max(fromLeft[i], fromLeft[i-1]);

    for(int i = (int)pos.size()-2; i >= 0; i--) 
      fromRight[i] = max(fromRight[i], fromRight[i+1]);

    /*
    for(int i = 0; i < n; i++)
      db(fromLeft[i]);

    for(int i = 0; i < n; i++)
      db(fromRight[i]);

    db(l);
    db(r);
    */

    string ans(n, '0');

    /*
     * Acho que nao precisa mais dessa parte
     * o algoritmo ja cobre esse caso de borda
    if(*max_element(begin(level), end(level)) <= m) {
      for(int i = 0; i < n; i++)
        cout << 1;
      cout << endl;
      continue;
    }
    */

    for(int i = 0; i < n; i++) {
      auto [xi, pi, idd] = v[i];

      auto idx = id(xi, pos);
      /*
      cerr << "\n-------------- valor inicial -------------------\n";
      db(xi);
      db(pi);
      db(idd);
      db(pi-xi);
      db(pi+xi);
      db(fromLeft[idx]);
      db(fromRight[idx]);
      */

      if(fromLeft[idx] <= pi-xi && fromRight[idx] <= pi+xi) ans[idd] = '1';
    }
    cout << ans << endl;
	}
}

// como resolver o terceiro ponto?
// agora eu sei quanto de agua vai ficar em cada ponto, se tem ate m de agua, entao nao tem problema
// pra cada um, eu tenho que ver quais pontos eu tenho q remover, pra soma ficar menor ou igual a m
// se chove um total de pj na posicao xj, entao eu preciso achar um ponto xi que chove pi tal que 
// pi-abs(xj-xi) >= level[xj]-m
//
// pi - abs(xj - xi) >= 2
//
// se xi > xj -> todo xi maior q xj
// pi - (xi - xj) >= level[xj] - m
// pi - xi >= level[xj] - m - xj
// pi - xi + xj >= 2
// pi - xi >= 2 - 1
// pi - xi >= level[xj] - m - xj
//
// se xi < xj -> todo xi menor q xj
// pi - xj + xi >= 2
// pi + xi >= 2 + 1
// pi - (xj - xi) >= level[xj] - m
// pi - xj + xi >= level[xj] - m
// pi + xi >= level[xj] - m + xj
//
//
// se xj > xi
//              -> pi - xj + xi >= level[xj] - m
//              -> xi + pi >= level[xj] - m + xj
// se xi > xj
//              -> pi - xi + xj >= level[xj] - m
//              -> xj - level[xj] + m >= xi - pi
//
// aqui eh a parte do two pointers ne?
// pra todo xj, eu tenho que encontrar quais xi, tal que 
// tal que oq? ahhhhhh da certo sim
// vou tentar aqui
// 1
// 3 6
// 1 5
// 5 5
// 3 4
// xi pi
//
// xi = 1 level[xi] = 8
// quais posicoes a direita podem fazer ele ficar bom?
// diff = level[xi] - m = 8 - 6 = 2
// formula = pj - abs(xj-xi) >= 2
// como xj > xi
// pj - xj + xi >= 2
// pj - xj >= 1
// pj - xj >= level[xi] - m - xi
// para xi = 1 level[xi] = 8 ------------------- pj -xj = 4
// pj - xj >= 8 - 6 - 1
// pj - xj >= 1 ---------------------------------------------
// para xi = 3 level[xi] = 10 ------------------ pj - xj = 1
// pj - xj >= 10 - 6 - 3
// pj - xj >= 1 ---------------------------------------------
// para xi = 5 level[xi] = 8 ------------------- pj - xj = 0
// pj - xj >= 8 - 6 - 5
// pj - xj >= -3 --------------------------------------------
// last = 5 
// unico que atende 
//
// xi = 1 level[xi] = 8
// quais posicoes a esquerda podem fazer ele ficar bom?
// diff = level[xi] - m = 8 - 6 = 2
// formula = pj - abs(xj-xi) >= 2
// como xj < xi
// pj - xi + xj >= 2
// pj + xj >= 2 + xi
// para xi = 1 level[xi] = 3 -------------------- pj + xj = 6
// pj + xj >= 3 ---------------------------------------------
//
// pj + xj >= level[xi] - m + xi
// para xi = 3 level[xi] = 10 ------------------- pj + xj = 7
// pj + xj >= 10 - 6 + 3
// pj + xj >= 7 ---------------------------------------------
//
// para xi = 5 level[xi] = 8 -------------------- pj + xj = 10
// pj + xj >= 8 - 6 + 5
// pj + xj >= 7 --------------------------------------------
// first = 1
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
// o que eh necessario para resolver o problema ?
// primeira observação eh que soh importa os pontos que ele da
// (quirino me explicou no discord e eu acredito)
// segundo ponto -> como calcular para cada ponto, quanto de agua cada um vai ter?
// terceiro e ultimo ponto -> sabendo quanto de agua cada ponto tem, calcular quanto eu preciso tirar
// para ficar abaixo de M e tambem, quais sao os pontos que se eu tirar atendem essa condição
// como faço o segundo ponto? 
// para todo ponto (pi, xi) ele cai no ponto xj se pi-abs(xi-xj) > 0
// se xi > xj
// pi - (xi - xj) > 0
// pi - xi + xj > 0
//                     -> pi - xi > -xj
//                     -> xi - pi < xj
// se xi < xj
// pi - (xj - xi) > 0
// pi - xj + xi > 0
// pi + xi - xj > 0
//                     -> pi + xi > xj
// como resolver isso?
// ordena o x
// para cada x, fazer uma seg em que o idx eh o xi e o valor eh pi-xi, e outra seg em que o valor eh pi+xi
// acho que nao da certo
// ter duas segs, ao ir da esquerda pra direita
// isso funciona
// preencher uma seg antes de iniciar o algoritmo, em que o idx eh o valor de pi +- xi (ver se eh mais ou menos)
// pra cada idx, apos processar, retirar ele dessa seg
// e acrescentar o oposto na seg indo da esquerda
//
// ok, resolvido o segundo ponto.
//
