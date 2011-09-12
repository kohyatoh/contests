#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int a[1000][1000], x[1000], y[1000];

int main() {
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) rep(j, n) scanf("%d", a[i]+j);
        rep(i, n) x[i]=y[i]=0;
        int xoc=0, yoc=0, xoi, yoi;
        rep(i, n) {
            rep(j, n) x[i]+=a[i][j];
            if(x[i]%2) xoc++, xoi=i;
        }
        rep(i, n) {
            rep(j, n) y[i]+=a[j][i];
            if(y[i]%2) yoc++, yoi=i;
        }
        if(xoc==0 && yoc==0) printf("OK\n");
        else if(xoc==1 && yoc==1) printf("Change bit (%d,%d)\n", xoi+1, yoi+1);
        else printf("Corrupt\n");
    }
}

