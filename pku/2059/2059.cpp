#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int f[1000][1000];
int x[1000], y[1000];

int main() {
    int T;
    scanf("%d", &T);
    rep(q, T) {
        int s, h;
        scanf("%d%d", &s, &h);
        rep(i, h) scanf("%d%d", x+i, y+i);
        rep(i, s+1) rep(j, s+1) f[i][j]=0;
        rep(i, h) f[x[i]][y[i]]=1;
        rep(i, s+1) rep(j, s+1) if(!f[i][j]) {
            int l=min(i*i, min(j*j, min((s-i)*(s-i), (s-j)*(s-j))));
            rep(k, h) if((x[k]-i)*(x[k]-i)+(y[k]-j)*(y[k]-j)>l) goto cont;
            printf("%d %d\n", i, j);
            goto nx;
cont:;
        }
        printf("poodle\n");
nx:;
    }
}
