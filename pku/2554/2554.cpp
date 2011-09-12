#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

#define INF (1<<30)

int m, n, a[3], k[10], s[10][10], t[10][10], g[3][10], w[3], pm[10], pe[10];
pair<int, int> r[3][10];

int alloc(int b) {
    rep(i, 3) w[i]=0;
    rep(i, n) {
        int ix=b%m;
        if(g[ix][i]==-1) return INF;
        r[ix][w[ix]].first = g[ix][i];
        r[ix][w[ix]].second = i;
        w[ix]++;
        b /= m;
    }
    rep(i, 3) sort(r[i], r[i]+w[i]);
    rep(i, m) rep(j, w[i]-1) r[i][j+1].first+=r[i][j].first;
    int s=0;
    rep(i, m) rep(j, w[i]) s+=r[i][j].first;
    return s;
}

int main() {
    for(int q=0;; q++) {
        scanf("%d%d", &m, &n);
        if(m==0 && n==0) return 0;
        rep(i, m) scanf("%d", a+i);
        rep(i, n) {
            scanf("%d", k+i);
            rep(j, k[i]) scanf("%d%d", s[i]+j, t[i]+j);
        }
        memset(g, -1, sizeof(g));
        rep(x, m) rep(i, n) rep(j, k[i]) if(s[i][j]<=a[x]) g[x][i] = t[i][j];
        int nn=1, mint=INF, minb=-1;
        rep(i, n) nn*=m;
        rep(b, nn) {
            int ct=alloc(b);
            if(mint>ct) mint=ct, minb=b;
        }
        alloc(minb);
        rep(i, m) rep(j, w[i]) {
            pm[r[i][j].second] = i;
            pe[r[i][j].second] = r[i][j].first;
        }
        printf("Case %d\n", q+1);
        printf("Average solution time = %d.%02d\n",
                (mint*1000/n+5)/10/100, (mint*1000/n+5)/10%100);
        rep(i, n) {
            printf("Problem %d is solved by member %d from %d to %d\n",
                    i+1, pm[i]+1, pe[i]-g[pm[i]][i], pe[i]);
        }
        printf("\n");
    }
}
