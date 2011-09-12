#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

double dp[2][200];

int main() {
    for(;;) {
        int C, N, M;
        scanf("%d", &C);
        if(C==0) return 0;
        scanf("%d%d", &N, &M);
        if(M>C) printf("%.3f\n", 0.0);
        else {
            memset(dp, 0, sizeof(dp));
            double *cur=dp[0], *nxt=dp[1];
            cur[0] = 1.0;
            rep(k, N) {
                bool f=true;
                rep(i, C+1) {
                    double p=0;
                    if(i!=0) p+=cur[i-1]*(C-i+1)/C;
                    if(i!=C) p+=cur[i+1]*(i+1)/C;
                    if(fabs(nxt[i]-p)>1e-5) f=false;
                    nxt[i] = p;
                }
                std::swap(cur, nxt);
                if(f && k%2!=N%2) break;
            }
            printf("%.3f\n", cur[M]);
        }
    }
}

