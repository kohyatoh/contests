#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int ipow(int a, int p) { int r=1; rep(i, p) r*=a; return r; }

char names[16][16];
double p[16][16], dp[5][256];
int ix[16];

int main() {
    rep(i, 16) scanf(" %s", names[i]);
    rep(i, 16) rep(j, 16) {
        int a;
        scanf("%d", &a);
        p[i][j] = a/100.0;
    }
    dp[0][0] = 1;
    rep(d, 4) {
        const int n=1<<(4-d), m=1<<d, k=n/2, mm=ipow(m, n), kk=1<<k;
        rep(bt, mm) {
            for(int t=bt, i=0; i<n; i++, t/=m) ix[i]=t%m;
            rep(b, kk) {
                int nbt=0;
                for(int i=k-1; i>=0; i--) {
                    const int wi = (b&(1<<i))==0 ? ix[i*2] : ix[i*2+1]+m;
                    nbt = nbt*(m*2) + wi;
                }
                double cp=1.0;
                rep(i, k) {
                    const int l=ix[i*2]+m*i*2, r=ix[i*2+1]+m*(i*2+1);
                    cp *= (b&(1<<i))==0 ? p[l][r] : p[r][l];
                }
                dp[d+1][nbt] += dp[d][bt]*cp;
            }
        }
    }
    rep(i, 16) printf("%-10s p=%.2f%%\n", names[i], dp[4][i]*100);
    return 0;
}
