#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, x[200], y[200];

int cross(int x1, int y1, int x2, int y2) { return x1*y2-x2*y1; }

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d%d", x+i, y+i);
    int ans=1;
    rep(i, n) rep(j, i) {
        int c=0;
        rep(k, n) if(cross(x[j]-x[i], y[j]-y[i], x[k]-x[i], y[k]-y[i])==0) c++;
        if(ans<c) ans=c;
    }
    printf("%d\n", ans);
    return 0;
}
