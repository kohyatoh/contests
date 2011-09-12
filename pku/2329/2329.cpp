#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, a[500][500], r[500][500], id[500][500];;
int dp[4][500][500], da[4][500][500], di[4][500][500];
int tmp[500][500];

void rotate(int (*b)[500]) {
    rep(i, n) rep(j, n) tmp[i][j]=b[j][n-1-i];
    rep(i, n) rep(j, n) b[i][j]=tmp[i][j];
}

int main() {
    scanf("%d", &n);
    rep(i, n) rep(j, n) scanf("%d", a[i]+j);
    int kk=1;
    rep(i, n) rep(j, n) id[i][j]=kk++;
    rep(D, 4) {
        rep(i, n) rep(j, n) dp[D][i][j]=-1;
        rep(i, n) rep(j, n) if(a[i][j]==0) {
            if(i>0 && a[i-1][j]>0) {
                dp[D][i][j]=1;
                da[D][i][j]=a[i-1][j];
                di[D][i][j]=id[i-1][j];
            }
            else if(i>0 && j>0 && dp[D][i-1][j]>=0 && dp[D][i][j-1]>=0) {
                if(dp[D][i-1][j]<dp[D][i][j-1]) {
                    dp[D][i][j]=dp[D][i-1][j]+1;
                    da[D][i][j]=da[D][i-1][j];
                    di[D][i][j]=di[D][i-1][j];
                }
                else if(dp[D][i-1][j]>dp[D][i][j-1]) {
                    dp[D][i][j]=dp[D][i][j-1]+1;
                    da[D][i][j]=da[D][i][j-1];
                    di[D][i][j]=di[D][i][j-1];
                }
                else if(di[D][i-1][j]==di[D][i][j-1]) {
                    dp[D][i][j]=dp[D][i-1][j]+1;
                    da[D][i][j]=da[D][i-1][j];
                    di[D][i][j]=di[D][i-1][j];
                }
                else {
                    dp[D][i][j]=dp[D][i-1][j]+1;
                    da[D][i][j]=0;
                    di[D][i][j]=0;
                }
            }
            else if(i>0 && dp[D][i-1][j]>=0) {
                dp[D][i][j]=dp[D][i-1][j]+1;
                da[D][i][j]=da[D][i-1][j];
                di[D][i][j]=di[D][i-1][j];
            }
            else if(j>0 && dp[D][i][j-1]>=0) {
                dp[D][i][j]=dp[D][i][j-1]+1;
                da[D][i][j]=da[D][i][j-1];
                di[D][i][j]=di[D][i][j-1];
            }
        }
        rotate(a);
        rep(i, D+1) rotate(dp[i]);
        rep(i, D+1) rotate(da[i]);
        rep(i, D+1) rotate(di[i]);
    }
    rep(i, n) rep(j, n) {
        if(a[i][j]>0) r[i][j]=a[i][j];
        else {
            int maxd=n*4;
            rep(D, 4) if(dp[D][i][j]>=0) {
                if(dp[D][i][j]<maxd) maxd=dp[D][i][j], r[i][j]=da[D][i][j];
                else if(dp[D][i][j]==maxd) r[i][j]=0;
            }
        }
    }
    rep(i, n) rep(j, n) printf("%d%c", r[i][j], j==n-1?'\n':' ');
    return 0;
}

