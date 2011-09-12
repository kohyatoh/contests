#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int N, P, c[100][100], l[100], h[100];

int main() {
    scanf("%d%d", &N, &P);
    rep(i, N) rep(j, P) scanf("%d", c[i]+j);
    rep(k, N) {
        int minc=1<<20, maxc=-1;
        rep(i, P) {
            if(minc>c[k][i]) minc=c[k][i];
            if(maxc<c[k][i]) maxc=c[k][i];
        }
        rep(i, P) {
            if(c[k][i]==minc) l[i]++;
            if(c[k][i]==maxc) h[i]++;
        }
    }
    int c=0;
    rep(i, P) {
        if(h[i]==0 && l[i]*2>=N) {
            if(c!=0) putchar(' ');
            printf("%d", i+1);
            c++;
        }
    }
    if(c==0) printf("%d", 0);
    putchar('\n');
    return 0;
}

