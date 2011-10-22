#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int N, M, R, C, f[128][128], s[128][128];

int sum(int x0, int y0, int x1, int y1) {
    if(x0<0) x0 = 0;
    if(y0<0) y0 = 0;
    return s[x1+1][y1+1] - s[x1+1][y0] - s[x0][y1+1] + s[x0][y0];
}

int main() {
    for(;;) {
        scanf("%d%d%d%d", &N, &M, &R, &C);
        if(N==0) return 0;
        memset(s, 0, sizeof(s));
        rep(i, N) rep(j, M) {
            char ch;
            scanf(" %c", &ch);
            f[i][j] = ch-'0';
        }
        int ans = 0;
        rep(i, N) rep(j, M) {
            s[i+1][j+1] = -s[i][j]+s[i+1][j]+s[i][j+1];
            if(i+R<=N && j+C<=M) {
                if(sum(i-R+1, j-C+1, i, j)%2!=f[i][j]) s[i+1][j+1]++, ans++;
            }
        }
        rep(i, N) rep(j, M) if(sum(i-R+1, j-C+1, i, j)%2!=f[i][j]) ans = -1;
        printf("%d\n", ans);
    }
}
