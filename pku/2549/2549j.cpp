#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, x[1000];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%d", x+i);
        sort(x, x+n);
        int ans=x[0]-1;
        for(int i=n-1; i>=0; i--) {
            for(int j=n-1; j>=2 && x[j]+x[j-1]+x[j-2]>=x[i]; j--) if(i!=j) {
                if(x[j]+x[1]+x[0]>x[i]) continue;
                for(int k=j-1; k>=1 && x[j]+x[k]+x[k-1]>=x[i]; k--) if(i!=k && x[j]!=-x[k]) {
                    if(x[j]+x[k]+x[0]>x[i]) continue;
                    int ix=lower_bound(x, x+k-1, x[i]-x[j]-x[k])-x;
                    if(x[i]==x[j]+x[k]+x[ix]) {
                        ans = x[i];
                        goto fin;
                    }
                }
            }
        }
fin:
        if(ans==x[0]-1) printf("no solution\n");
        else printf("%d\n", ans);
    }
}

