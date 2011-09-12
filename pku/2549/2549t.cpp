#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

#define INF (1<<30)
int n, x[1000], y[1000000];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%d", x+i);
        int m = 0;
        sort(x, x+n);
        rep(i, n) rep(j, i) y[m++] = x[j]-x[i];
        sort(y, y+m);
        rep(i, n) rep(j, i) y[m++] = x[i]-x[j];
        sort(y+m/2, y+m);
        int ans=x[0]-1;
        for(int i=n-1; i>=2 && x[i]+x[i-1]+x[i-2]>ans; i--) {
            for(int j=i-1; j>=1 && x[i]+x[j]+x[j-1]>ans; j--) if(x[i]+x[j]!=0) {
                if(!binary_search(y, y+m, x[i]+x[j])) continue;
                for(int k=j-1; k>=0 && x[i]+x[j]+x[k]>ans; k--) {
                    if(x[i]+x[j]+x[k]>x[n-1]) continue;
                    if(x[i]+x[j]+x[k]<x[0]) break;
                    if(x[i]+x[k]==0 || x[j]+x[k]==0) continue;
                    int ix=lower_bound(x, x+n, x[i]+x[j]+x[k])-x;
                    if(ix<n && x[ix]==x[i]+x[j]+x[k]) {
                        ans = max(ans, x[ix]);
                        break;
                    }
                }
            }
        }
        if(ans==x[0]-1) printf("no solution\n");
        else printf("%d\n", ans);
    }
}

