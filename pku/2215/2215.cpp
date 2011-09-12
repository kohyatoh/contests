#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int T, R, S, a[1024][1024], s[1024][1024], D, r1, s1, r2, s2;

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &R, &S);
        rep(i, R) rep(j, S) scanf("%d", a[i]+j);
        rep(i, R) rep(j, S) s[i+1][j+1]=a[i][j]+s[i][j+1]+s[i+1][j]-s[i][j];
        scanf("%d", &D);
        while(D--) {
            scanf("%d%d%d%d", &r1, &s1, &r2, &s2);
            r1--, s1--, r2--, s2--;
            int ans=s[r2+1][s2+1]+s[r1][s1]-s[r2+1][s1]-s[r1][s2+1];
            printf("Absolutni hodnota pohodlnosti je %d bodu.\n", ans);
        }
        puts("");
    }
    return 0;
}
