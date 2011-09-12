#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

#define FINF (1e100)
int n, s[100], x[100][50], y[100][50];
double dp[2][40];

#ifndef UNIX
double hypot(double x, double y) { return sqrt(x*x+y*y); }
#endif

int main() {
    scanf("%d", &n);
    rep(i, n) {
        scanf("%d", s+i);
        rep(j, s[i]) scanf("%d%d", x[i]+j, y[i]+j);
    }
    double ans=FINF;
    rep(ini, s[0]) {
        double *cur=dp[0], *nxt=dp[1];
        rep(i, s[0]) cur[i]=FINF;
        cur[ini]=0;
        for(int i=1; i<=n; i++) {
            rep(j, s[i%n]) {
                nxt[j]=FINF;
                rep(k, s[i-1]) {
                    double dist=hypot(x[i%n][j]-x[i-1][k], y[i%n][j]-y[i-1][k]);
                    nxt[j]=min(nxt[j], cur[k]+dist);
                }
            }
            swap(cur, nxt);
        }
        ans = min(ans, cur[ini]);
    }
    printf("%d\n", (int)(ans*100));
    return 0;
}
