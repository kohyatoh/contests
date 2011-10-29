#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
typedef long long Int;

struct BIT {
    vector<Int> x;
    void add(int k, Int a) { for(; k<(int)x.size(); k|=k+1) x[k]+=a; }
    Int sum() { return sum(x.size()-1); }
    Int sum(int k) {
        if(x.size()==1) return x[0];
        Int s=0; for(; k>=0; k=(k&(k+1))-1) s+=x[k]; return s;
    }
    Int rsum(int i, int j) { return i==0 ? sum(j) : sum(j)-sum(i-1); }
};

int n, Q, cnt[60000], root[60000], pof[60000], qof[60000];
Int rs[60000];
vector<int> g[60000], org[60000];
vector<int> a[60000];
BIT sum[60000], add[60000];

void build(int at) {
    pof[at] = at;
    qof[at] = 0;
    cnt[at] = 1;
    org[at].push_back(at);
    while(g[at].size()==1) {
        const int v = g[at][0];
        pof[v] = at;
        qof[v] = a[at].size();
        org[at].push_back(v);
        cnt[at]++;
        a[at].push_back(a[v][0]);
        a[v].clear();
        g[at].clear();
        rep(i, g[v].size()) g[at].push_back(g[v][i]);
        g[v].clear();
    }
    add[at].x.resize(a[at].size());
    sum[at].x.resize(a[at].size());
    rep(i, a[at].size()) sum[at].add(i, a[at][i]);
    rep(i, g[at].size()) {
        const int v = g[at][i];
        build(v);
        cnt[at] += cnt[v];
        sum[at].add(a[at].size()-1, sum[v].sum());
    }
}

void flatten(int at, Int F) {
    rep(i, a[at].size()) {
        rs[org[at][i]] = a[at][i] + F + add[at].sum(i);
    }
    F += add[at].sum();
    rep(i, g[at].size()) {
        const int v = g[at][i];
        flatten(v, F);
    }
}

void employee(int at, int ix, int y, int z) {
    Int cur = a[at][ix] + add[at].sum(ix);
    if(cur>=y) return ;
    for(int k=root[at]; k!=-1; k=root[k]) {
        cur += add[k].sum();
        if(cur>=y) return ;
    }
    a[at][ix] += z;
    sum[at].add(ix, z);
    for(int k=root[at]; k!=-1; k=root[k]) {
        sum[k].add(a[k].size()-1, z);
    }
}

void department(int at, int ix, int y, int z) {
    const Int c = cnt[at]-ix;
    Int cur = sum[at].rsum(ix, a[at].size()-1) + add[at].sum(ix)*c;
    if(cur>=y*c) return ;
    for(int k=root[at]; k!=-1; k=root[k]) {
        cur += add[k].sum()*c;
        if(cur>=y*c) return ;
    }
    add[at].add(ix, z);
    sum[at].add(ix, z*c);
    for(int k=root[at]; k!=-1; k=root[k]) {
        sum[k].add(a[k].size()-1, z*c);
    }
}

int main() {
    int r, _a;
    scanf("%d%d%d", &n, &Q, &_a);
    a[0].push_back(_a);
    root[0] = -1;
    rep(i, n-1) {
        scanf(" %d%d", &r, &_a);
        a[i+1].push_back(_a);
        root[i+1] = r;
        g[r].push_back(i+1);
    }
    build(0);
    char op[16];
    int x, y, z;
    rep(_, Q) {
        scanf(" %s%d%d%d", op, &x, &y, &z);
        if(op[0]=='e') employee(pof[x], qof[x], y, z);
        else department(pof[x], qof[x], y, z);
    }
    flatten(0, 0);
    rep(i, n) cout << rs[i] << endl;
    return 0;
}

