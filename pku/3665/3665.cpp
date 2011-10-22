#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int N, T, a[1000];

int main() {
    scanf("%d%d", &N, &T);
    rep(i, N) scanf("%d", a+i);
    rep(_, T) {
        int ix = 0;
        rep(i, N) if(a[ix]<a[i]) ix = i;
        printf("%d\n", ix+1);
        int x = a[ix]/(N-1), y = a[ix]%(N-1);
        a[ix] = 0;
        rep(i, N) if(i!=ix) {
            a[i] += x;
            if(y-->0) a[i] += 1;
        }
    }
    return 0;
}
