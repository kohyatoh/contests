#include <stdio.h>
#include <queue>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, flow[500][500], capa[500][500], prev[500];

int maxFlow(int s, int t) {
    int total=0;
    rep(i, n) rep(j, n) flow[i][j]=0;
    for(;;) {
        queue<int> q; q.push(s);
        rep(i, n) prev[i]=-1;
        prev[s]=s;
        while(!q.empty() && prev[t]<0) {
            int u=q.front(); q.pop();
            rep(i, n) if(prev[i]<0 && capa[u][i]>flow[u][i]) {
                prev[i]=u; q.push(i);
            }
        }
        if(prev[t]<0) return total;
        int inc=1<<30;
        for(int j=t; prev[j]!=j; j=prev[j]) inc=min(inc, capa[prev[j]][j]-flow[prev[j]][j]);
        for(int j=t; prev[j]!=j; j=prev[j]) flow[prev[j]][j]+=inc, flow[j][prev[j]]-=inc;
        total+=inc;

    }
}

int main() {
    while(scanf("%d", &n)!=EOF) {
        rep(i, n+100) rep(j, n+100) capa[i][j]=0;
        rep(i, n) capa[0][i+100]=capa[i+100][0]=1;
        rep(i, 84) capa[1][i+2]=capa[i+2][1]=1;
        rep(i, n) {
            int t;
            scanf("%d", &t);
            rep(j, t) {
                int p, q;
                scanf("%d%d", &p, &q);
                int c=(p-1)*12+q-1;
                capa[i+100][c+2]=capa[c+2][i+100]=1;
            }
        }
        n+=100;
        printf("%d\n", maxFlow(0, 1));
    }
    return 0;
}
