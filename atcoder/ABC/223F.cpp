#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"

struct node {
        int left, right;
        node(): left(0), right(0) {}
        node(int l, int r): left(l), right(r) {}
};

struct ST {
        vector<node> st;
        int n;

        ST() {}
        ST(int _n): n(_n) {
                st.resize(4*n);
        }

        node merge(node a, node b) {
                if(a.right == b.left)
                        return node(a.left, b.right);

                int dif = abs(a.right-b.left);

                if(a.right > b.left) {
                        db(a.left);
                        db(a.right);
                        db(b.left);
                        db(b.right);
                        db(dif);
                        db(node(a.left, b.right+dif).left);
                        db(node(a.left, b.right+dif).right);
                        return node(a.left, b.right + dif);
                }else {
                        return node(a.left + dif, b.right);
                }
        }

        node update(int id, node no, int sti, int stl, int str) {
                if(id > str || id < stl) return st[sti];
                if(stl == str) return st[sti] = no;
                int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;
                st[sti] = merge(update(id, no, ste, stl, stm), update(id, no, std, stm+1, str));

                cout << "------------------------- db ----------------------\n";
                db(id);
                db(no.left);
                db(no.right);
                db(sti);
                db(stl);
                db(str);
                db(st[sti].left);
                db(st[sti].right);
                db(st[ste].left);
                db(st[ste].right);
                db(st[std].left);
                db(st[std].right);
                return st[sti];
        }

        node query(int L, int R, int sti, int stl, int str) {
                if(L > str || R < stl) return node();
                if(stl <= L && R <= str) return st[sti];
                int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;
                return merge(query(L, R, ste, stl, stm), query(L, R, std, stm+1, str));

        }

        node update(int id, node no) {
                return update(id, no, 1, 0, n-1);
        }

        node query(int L, int R) {
                return query(L, R, 1, 0, n-1);
        }

};

node convert(char c) {
        if(c == ')') return node(1, 0);
        return node(0, 1);
}

int main() {
        cin.tie(0)->sync_with_stdio(false);

        int n, q;
        string s;
        cin >> n >> q >> s;

        ST st(n);

        for(int i = 0; i < n; i++) {
                auto cur = st.update(i, convert(s[i]));
                cout << "dbg\n";
                cout << cur.left << ' ' << cur.right << endl;
        }

        while(q--) {
                int type, l, r;
                cin >> type >> l >> r;
                l--, r--;
                if(type == 1) {
                        // swap lth char with rth char
                        st.update(l, convert(s[r]));
                        st.update(r, convert(s[l]));
                        swap(s[l], s[r]);
                }else {
                        // output whether the contiguous substring s[l:r] is a correct bracket sequence
                        auto no = st.query(l, r);
                        cout << no.left << " " << no.right << endl;
                        if(!no.left && !no.right) cout << "Yes\n";
                        else cout << "No\n";
                }
        }
}
