#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1000000000)

int n, L, a[10000], dp[2][10000];

int main() {
    scanf("%d%d", &n, &L);
    rep(i, n) scanf("%d", a+i);
    if(n==1) {
        printf("%d\n", 0);
        return 0;
    }
    int d=L/(n-1), m=L%(n-1)+1;
    int *cur=dp[0], *nxt=dp[1];
    rep(i, m) cur[i] = INF;
    cur[0] = a[0];
    for(int i=1; i<n; i++) {
        const int s = i*d;
        nxt[0] = cur[0]+abs(a[i]-s);
        for(int x=1; x<m; x++) {
            nxt[x] = min(cur[x], cur[x-1])+abs(a[i]-s-x);
        }
        swap(cur, nxt);
    }
    int ans = INF*2;
    printf("%d\n", cur[m-1]);
    return 0;
}
