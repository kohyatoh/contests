#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int a[1024][1024];

bool solve(int n) {
    if(n==1) return true;
    if(a[0][0]+a[1][1]!=a[0][1]+a[1][0]) return false;
    for(int k=2; k<n; k++) {
        if(a[0][k]-a[0][1]!=a[1][k]-a[1][1]) return false;
    }
    for(int k=2; k<n; k++) {
        const int z = a[k][0]-a[1][0];
        rep(i, n) if(a[k][i]-a[1][i]!=z) return false;
    }
    return true;
}

char buf[10000];

int main() {
    for(;;) {
        gets(buf);
        const int n = atoi(buf);
        if(n==0) return 0;
        rep(i, n) {
            gets(buf);
            char *p = buf;
            rep(j, n) {
                int x = 0, sign = 1;
                if(*p=='-') sign = -1, p++;
                while('0'<=*p) {
                    x = x*10+*p-'0';
                    p++;
                }
                a[i][j] = x*sign;
                p++;
            }
        }
        printf("%shomogeneous\n", solve(n) ? "" : "not ");
    }
}
