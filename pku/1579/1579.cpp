#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int dp[32][32][32];

int w(int a, int b, int c) {
    if(a<=0 || b<=0 || c<=0) return 1;
    if(a>20 || b>20 || c>20) return w(20, 20, 20);
    return dp[a][b][c];
}

int main() {
    rep(a, 21) rep(b, 21) rep(c, 21) {
        dp[a][b][c] = (a<b && b<c) ?
            w(a, b, c-1)+w(a, b-1, c-1)-w(a, b-1, c)
            : w(a-1, b, c)+w(a-1, b-1, c)+w(a-1, b, c-1)-w(a-1, b-1, c-1);
    }
    for(;;) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if(a==-1 && b==-1 && c==-1) return 0;
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
}
