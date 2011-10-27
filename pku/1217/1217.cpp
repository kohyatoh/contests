#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

const int ac[4][4] = {
    {1, 1, 1, 2},
    {0, 0, 0, 1},
    {0, 0, 0, 1},
    {-1, 0, 0, 0},
};

const int bc[4][4] = {
    {0, -1, -1, -1},
    {1, 0, 0, 0},
    {1, 0, 0, 0},
    {2, 0, 0, -1},
};

#define B (64)
double dp[32][128];

int main() {
    dp[0][B] = 1;
    rep(i, 20) rep(j, 128) if(dp[i][j]!=0.0) {
        rep(a, 4) rep(b, 4) {
            const int df = ac[a][b] - bc[a][b];
            dp[i+1][j+df] += dp[i][j]/16;
        }
    }
    puts("Round   A wins    B wins    Tie");
    rep(i, 20) {
        double a = 0, b = 0, c = 0;
        rep(j, 128) {
            if(j>B) a += dp[i+1][j];
            else if(j<B) b += dp[i+1][j];
            else c += dp[i+1][j];
        }
        printf("%5d   %7.4f%%  %7.4f%%  %7.4f%%\n", i+1, a*100, b*100, c*100);
    }
    return 0;
}
