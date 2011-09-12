#include <stdio.h>
#include <algorithm>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int L, n, m, d[60000];

bool can(int len) {
    int r=0, p=0;
    rep(i, n) {
        if(L-d[i]<len) r++;
        else {
            if(d[i]-p<len) r++;
            else p=d[i];
        }
    }
    return r<=m;
}

int main() {
    scanf("%d%d%d", &L, &n, &m);
    rep(i, n) scanf("%d", d+i);
    std::sort(d, d+n);
    int l=0, r=L+1, m;
    while(r-l>1) {
        m = (l+r)/2;
        if(can(m)) l=m;
        else r=m;
    }
    printf("%d\n", l);
    return 0;
}

