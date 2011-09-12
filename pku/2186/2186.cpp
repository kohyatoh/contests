#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, color[10000], order[10000], size[10000], on;
vector<int> g[10000], h[10000];

void scc_visit_1(int at, int col) {
    if(color[at]>=0) return ;
    color[at]=col;
    rep(i, g[at].size()) scc_visit_1(g[at][i], col);
    order[on++]=at;
}

void scc_visit_2(int at, int col) {
    if(color[at]>=0) return ;
    color[at]=col;
    size[col]++;
    rep(i, h[at].size()) scc_visit_2(h[at][i], col);
}

int scc() {
    on=0;
    fill_n(color, n, -1);
    rep(i, n) scc_visit_1(i, i);
    fill_n(color, n, -1);
    int last=0;
    rep(i, n) if(color[order[n-1-i]]<0) {
        scc_visit_2(order[n-1-i], i);
        last=order[n-1-i];
    }
    return last;
}

int vis[10000];
int kount(int at) {
    if(vis[at]) return 0;
    vis[at]=1;
    int s=1;
    rep(i, h[at].size()) s+=kount(h[at][i]);
    return s;
}

int main() {
    int m, a, b;
    scanf("%d%d", &n, &m);
    rep(i, m) {
        scanf("%d%d", &a, &b); a--; b--;
        g[a].push_back(b);
        h[b].push_back(a);
    }
    int ans=0;
    int top=scc();
    if(kount(top)==n) ans=size[color[top]];
    printf("%d\n", ans);
    return 0;
}

