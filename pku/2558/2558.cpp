#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, x[5000];
char of[]="NOP";

bool rec(int k, int y) {
    if(k==5000) return true;
    x[k]=y;
    for(int j=2; k+1-j*2>=0; j++) {
        bool eq=true;
        rep(i, j) if(x[k+1-j*2+i]!=x[k+1-j+i]) { eq=false; break; }
        if(eq) return false;
    }
    if(y!=0 && rec(k+1, 0)) return true;
    if(y!=1 && rec(k+1, 1)) return true;
    if(y!=2 && rec(k+1, 2)) return true;
    return false;
}

int main() {
    rec(1, 1);
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) putchar(of[x[i]]);
        putchar('\n');
    }
}
