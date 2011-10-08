#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int H, W, S, U[32][32], L;
int sm[64][64], dp[32][32][32][32], memo[32][32][32][32];

inline void cmax(int& a, int b) { if(a<b) a = b; }

inline int sum(int i, int j, int l, int r) {
    return sm[j+1][r+1]-sm[i][r+1]-sm[j+1][l]+sm[i][l];
}

int rec(int i, int j, int l, int r) {
    if(dp[i][j][l][r]==1) return sum(i, j, l, r)-L;
    if(memo[i][j][l][r]!=-1) return memo[i][j][l][r];
    int ans = 0;
    for(int a=l; a<r; a++) if(dp[i][j][l][a] && dp[i][j][a+1][r]) {
        if(dp[i][j][l][r]==dp[i][j][l][a]+dp[i][j][a+1][r]) {
            cmax(ans, min(rec(i, j, l, a), rec(i, j, a+1, r)));
        }
    }
    for(int a=i; a<j; a++) if(dp[i][a][l][r] && dp[a+1][j][l][r]) {
        if(dp[i][j][l][r]==dp[i][a][l][r]+dp[a+1][j][l][r]) {
            cmax(ans, min(rec(i, a, l, r), rec(a+1, j, l, r)));
        }
    }
    return memo[i][j][l][r] = ans;
}

int main() {
    for(;;) {
        scanf("%d%d%d", &H, &W, &S);
        if(H==0 && W==0 && S==0) return 0;
        rep(i, H) rep(j, W) scanf("%d", U[i]+j);
        rep(i, H) rep(j, W) {
            sm[i+1][j+1] = U[i][j]-sm[i][j]+sm[i][j+1]+sm[i+1][j];
        }
        L = sm[H][W]-S;
        rep(h, H) rep(i, H-h) {
            const int j = i+h;
            rep(w, W) rep(l, W-w) {
                const int r = l+w;
                dp[i][j][l][r] = sum(i, j, l, r)>=L;
                for(int a=l; a<r; a++) if(dp[i][j][l][a] && dp[i][j][a+1][r]) {
                    cmax(dp[i][j][l][r], dp[i][j][l][a]+dp[i][j][a+1][r]);
                }
                for(int a=i; a<j; a++) if(dp[i][a][l][r] && dp[a+1][j][l][r]) {
                    cmax(dp[i][j][l][r], dp[i][a][l][r]+dp[a+1][j][l][r]);
                }
            }
        }
        memset(memo, -1, sizeof(memo));
        printf("%d %d\n", dp[0][H-1][0][W-1], rec(0, H-1, 0, W-1));
    }
}
