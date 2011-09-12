#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, x[1000];
int nx, v[1000], vn;

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        for(;;) {
            scanf("%d", x);
            if(x[0]==0) break;
            rep(i, n-1) scanf("%d", x+i+1);
            nx=1, vn=0;
            bool yes=true;
            rep(i, n) {
                if(x[i]>=nx) {
                    for(int y=nx; y<x[i]; y++) v[vn++]=y;
                    nx=x[i]+1;
                }
                else {
                    if(vn==0 || v[vn-1]!=x[i]) {
                        yes=false;
                        break;
                    }
                    vn--;
                }
            }
            puts(yes ? "Yes" : "No");
        }
        puts("");
    }
}
