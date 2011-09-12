#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, b, q, h[256][256], mn[10][256][256], mx[10][256][256];
int m, w[10];

int main() {
    scanf("%d%d%d", &n, &b, &q);
    rep(i, n) rep(j, n) scanf("%d", h[i]+j);
    w[0]=b;
    while(w[m]>1) {
        w[m+1] = (w[m]+1)/2;
        m++;
    }
    rep(i, n) rep(j, n) mn[m][i][j]=mx[m][i][j]=h[i][j];
    for(int k=m-1; k>=0; k--) {
        int d=w[k]-w[k+1];
        rep(i, n-w[k]+1) rep(j, n-w[k]+1) {
            mn[k][i][j]=min(min(mn[k+1][i][j], mn[k+1][i+d][j+d]),
                            min(mn[k+1][i][j+d], mn[k+1][i+d][j]));
            mx[k][i][j]=max(max(mx[k+1][i][j], mx[k+1][i+d][j+d]),
                            max(mx[k+1][i][j+d], mx[k+1][i+d][j]));
        }
    }
    rep(i, q) {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%d\n", mx[0][u-1][v-1]-mn[0][u-1][v-1]);
    }
    return 0;
}
