#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define fst first
#define snd second
typedef long long Int;

struct UnionSet {
    int ud[6000];
    void init() { memset(ud, -1, sizeof(ud)); }
    int root(int x) { return ud[x]<0 ? x : ud[x]=root(ud[x]); }
    int size(int x) { return -ud[root(x)]; }
    bool same(int x, int y) { return root(x)==root(y); }
    bool set(int x, int y) {
        x=root(x); y=root(y);
        if(x!=y) {
            if(ud[y]<ud[x]) std::swap(x, y);
            ud[x]+=ud[y]; ud[y]=x;
        }
        return x!=y;
    }
} us;

int n, m1, m2;
pair<int, pair<int, int> > e1[30000];
pair<int, pair<int, int> > e2[30000];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m1, &m2);
        rep (i, m1) scanf("%d%d%d", &e1[i].snd.fst, &e1[i].snd.snd, &e1[i].fst);
        rep (i, m2) scanf("%d%d%d", &e2[i].snd.fst, &e2[i].snd.snd, &e2[i].fst);
        sort(e1, e1+m1);
        sort(e2, e2+m2);
        reverse(e2, e2+m2);
        us.init();
        Int a1 = 0, a2 = 0;
        rep (i, m2) if (us.set(e2[i].snd.fst, e2[i].snd.snd)) a1 += e2[i].fst;
        rep (i, m1) if (us.set(e1[i].snd.fst, e1[i].snd.snd)) a2 += e1[i].fst;
        if (us.size(0) == n) {
            cout << a1 << ' ' << (a1+a2) << endl;
        }
        else {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}
