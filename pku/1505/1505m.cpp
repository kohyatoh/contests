#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int T, n, m, p[500];

int kount(int i, long long u) {
    long long s=0;
    int c=1;
    for(; i<n; i++) {
        if(p[i]>u) return 1<<20;
        else if(s+p[i]<=u) s+=p[i];
        else s=p[i], c++;
    }
    return c;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        rep(i, n) scanf("%d", p+i);
        long long l=0, r=0, mid;
        rep(i, n) r+=p[i];
        while(r-l>1) {
            mid = (l+r)/2;
            if(kount(0, mid)>m) l=mid;
            else r=mid;
        }
        int x=0;
        rep(i, m) {
            printf(i?" / %d":"%d", p[x++]);
            while(x<n && kount(x, r)>m-i-1) printf(" %d", p[x++]);
        }
        puts("");
    }
    return 0;
}

