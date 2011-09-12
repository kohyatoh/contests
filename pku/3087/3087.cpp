#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n;
char f[300], g[300], e[300];

int search() {
    rep(k, n*2) {
        rep(i, n) g[i*2+1] = f[i];
        rep(i, n) g[i*2] = f[n+i];
        memcpy(f, g, n*2);
        if(strcmp(f, e)==0) return k+1;
    }
    return -1;
}

int main() {
    int T;
    scanf("%d", &T);
    rep(_t, T) {
        memset(f, 0, sizeof(f));
        memset(e, 0, sizeof(e));
        scanf("%d", &n);
        rep(i, n*2) scanf(" %c", f+i);
        rep(i, n*2) scanf(" %c", e+i);
        printf("%d %d\n", _t+1, search());
    }
    return 0;
}
