#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, r, d, g[200][200];
char a[80], b[80];

int main() {
    for(int q=0;; q++) {
        scanf("%d%d", &n, &r);
        if(n==0) return 0;
        memset(g, 0, sizeof(g));
        map<string, int> ids;
        int m=0;
        rep(i, r) {
            scanf(" %s%s%d", a, b, &d);
            int aix = ids.find(a)!=ids.end() ? ids[a] : (ids[a]=m++);
            int bix = ids.find(b)!=ids.end() ? ids[b] : (ids[b]=m++);
            g[aix][bix] = max(g[aix][bix], d);
            g[bix][aix] = max(g[bix][aix], d);
        }
        rep(k, n) rep(i, n) rep(j, n) {
            g[i][j]=max(g[i][j], min(g[i][k], g[k][j]));
        }
        scanf(" %s%s", a, b);
        printf("Scenario #%d\n", q+1);
        printf("%d tons\n", g[ids[a]][ids[b]]);
        printf("\n");
    }
}

