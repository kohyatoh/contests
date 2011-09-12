#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int r, n, x[1000], f[3000];

int main() {
    for(;;) {
        scanf("%d%d", &r, &n);
        if(r==-1) return 0;
        rep(i, n) scanf("%d", x+i);
        rep(i, 3000) f[i]=0;
        rep(i, n) f[x[i]]=1;
        int ans=0;
        rep(i, 1001) if(f[i]) {
            int k=i+r;
            while(f[k]==0) k--;
            for(int t=-r; t<=r; t++) if(k+t>=0) f[k+t]=0;
            ans++;
        }
        printf("%d\n", ans);
    }
}
