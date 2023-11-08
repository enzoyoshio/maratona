#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5+8;
const int MAXM = 1e6+8;
const int MLOG = 30;
int n, q;

bitset<MAXM> a;
vector<int> phi(MAXM);

void build() {
  a.set();

  for(int i = 1; i < MAXM; i++) {
    phi[i] = i;
    if(i%2 == 0) phi[i] /= 2;
  }

  for(int i = 3; i < MAXM; i+=2) {
    if(a[i]) {
      for(int j = i; j < MAXM; j+=i) {
        a[j] = false;
        phi[j] /= i;
        phi[j] *= (i-1);
      }
    }
  }
}

struct node {
  array<int, MLOG> v;

  node() { for(int i = 0; i < MLOG; i++) v[i] = 0;}

  node(int x) {
    for(int i = 0; i < MLOG; i++) {
      if(!i) v[i] = x;
      else v[i] = phi[v[i-1]];
    }
  }
};

vector<node> st(4*MAXN, node());
vector<int> lazy1(4*MAXN, 0), lazy2(4*MAXN, 0);

node f(node a, node b) {
  for(int i = 0; i < MLOG; i++) {
    a.v[i] += b.v[i];
  }
  return a;
}

void prop(int sti, int stl, int str) {
  // setting X is weaker?stronger then applying phi(ai)
  if(lazy2[sti]) {

    int tam = str-stl+1;
    st[sti] = node(lazy2[sti]);

    for(int i = 0; i < MLOG; i++)
      st[sti].v[i] *= tam;

    if(stl != str) {
      lazy2[2*sti] = lazy2[sti];
      lazy2[2*sti+1] = lazy2[sti];
    }

    lazy2[sti] = 0;
    lazy1[sti] = 0;
  }

  if(lazy1[sti]) {

    for(int i = 0; i < MLOG; i++) {
      if(i + lazy1[sti] < MLOG) st[sti].v[i] = st[sti].v[i+lazy1[sti]];
      else if(i) st[sti].v[i] = st[sti].v[i-1];
      else st[sti].v[i] = st[sti].v[MLOG-1];
    }

    if(stl != str) {
      lazy1[2*sti] += lazy1[sti];
      lazy1[2*sti+1] += lazy1[sti];
    }

    lazy1[sti] = 0;
  }
}

// third query -> answer the sum in the range
node query(int L, int R, int sti, int stl, int str) {
  prop(sti, stl, str);
  if(L > str || stl > R) return node();

  if(L <= stl && str <= R) return st[sti];

  int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;

  return f(query(L, R, ste, stl, stm), query(L, R, std, stm+1, str));
}
node query(int L, int R) { return query(L, R, 1, 0, n-1);}

// first query -> change ai to phi(ai);
// shake
node update1(int L, int R, int sti, int stl, int str) {
  prop(sti, stl, str);
  if(L > str || stl > R) return st[sti];

  if(L <= stl && str <= R) {
    lazy1[sti]++;
    prop(sti, stl, str);
    return st[sti];
  }

  int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;

  return st[sti] = f(update1(L, R, ste, stl, stm),
                     update1(L, R, std, stm+1, str));
}
node update1(int L, int R) { return update1(L, R, 1, 0, n-1);}

// second query -> set ai to x;
node update2(int L, int R, int x, int sti, int stl, int str) {
  prop(sti, stl, str);
  if(L > str || stl > R) return st[sti];

  if(L <= stl && str <= R) {
    lazy2[sti] = x;
    prop(sti, stl, str);
    return st[sti];
  }

  int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;

  return st[sti] = f(update2(L, R, x, ste, stl, stm),
                     update2(L, R, x, std, stm+1, str));
}
node update2(int L, int R, int x) { return update2(L, R, x, 1, 0, n-1);}

auto main() -> signed {
  cin.tie(0)->sync_with_stdio(false);

  build();

  cin >> n >> q;

  for(int i = 0; i < n; i++) {
    int a; cin >> a;
    update2(i, i, a);
  }

  while(q--) {
    int t, l, r; cin >> t >> l >> r;
    l--, r--;

    if(t == 1) {
      update1(l, r);
    }else if(t == 2) {
      int x; cin >> x;
      update2(l, r, x);
    }else {
      cout << query(l, r).v[0] << '\n';
    }
  }
}
