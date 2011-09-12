#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

void re(int r, int h, int o) {
    int k=1;
    rep(i, r) k*=2;
    if(r==1) {
        if(h==0) printf(" /\\%c", o?'\n':' ');
        else {
            printf("/__\\");
            if(o) putchar('\n');
        }
    }
    else {
        if(h<k/2) {
            rep(i, k/2) putchar(' ');
            re(r-1, h, o);
            if(!o) rep(i, k/2) putchar(' ');
        }
        else {
            re(r-1, h-k/2, 0);
            re(r-1, h-k/2, o);
        }
    }
}

int main() {
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        int k=1;
        rep(i, n) k*=2;
        rep(h, k) re(n, h, 1);
        puts("");
    }
}
