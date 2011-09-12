#include <stdio.h>

int p, q, a, n;

int rec(int m, int x, int y, int last) {
    if(m>n || x*q > p*y) return 0;
    if(x*q == p*y) return 1;
    int ans = 0;
    for(int i=last; y*i<=a; i++) {
        // x/y + 1/i
        ans += rec(m+1, x*i+y, y*i, i);
    }
    return ans;
}

int main() {
    for(;;) {
        scanf("%d%d%d%d", &p, &q, &a, &n);
        if(p==0 && q==0 && a==0 && n==0) return 0;
        printf("%d\n", rec(0, 0, 1, 1));
    }
}
