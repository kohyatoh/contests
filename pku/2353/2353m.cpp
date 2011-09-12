#include <stdio.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (2000000000)

int M, N, f[100][500], d[101][500];
int Z, t[50000];

void print(int m, int n) {
    while(m>1) {
        t[Z++] = n;
        if(d[m][n]-f[m-1][n]==d[m-1][n]) m--;
        else if(n>0 && d[m][n]-f[m-1][n]==d[m][n-1]) n--;
        else n++;
    } 
    t[Z++] = n;
    for(int i=Z-1; i>=0; i--) printf("%d\n", t[i]+1);
}

int main() {
    scanf("%d%d", &M, &N);
    rep(i, M) rep(j, N) scanf("%d", f[i]+j);
    for(int k=1; k<=M; k++) {
        rep(i, N) d[k][i]=d[k-1][i]+f[k-1][i];
        rep(i, N-1) {
            if(d[k][i+1]>d[k][i]+f[k-1][i+1]) d[k][i+1]=d[k][i]+f[k-1][i+1];
        }
        for(int i=N-1; i>0; i--) {
            if(d[k][i-1]>d[k][i]+f[k-1][i-1]) d[k][i-1]=d[k][i]+f[k-1][i-1];
        }
    }
    int mind=INF, mini=-1;
    rep(i, N) if(mind>d[M][i]) mind=d[M][i], mini=i;
    print(M, mini);
    return 0;
}
