#include <stdio.h>
#include <algorithm>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, c, x[100000];

bool can(int d) {
    int k=0, pre=-d;
    rep(i, n) if(x[i]-pre>=d) pre=x[i], k++;
    return k>=c;
}

int main() {
    scanf("%d%d", &n, &c);
    rep(i, n) scanf("%d", x+i);
    std::sort(x, x+n);
    int l=0, r=100000000, m;
    while(r-l>1) {
        m = (l+r)/2;
        if(can(m)) l=m;
        else r=m;
    }
    printf("%d\n", l);
    return 0;
}
