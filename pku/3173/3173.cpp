#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int a[32][32];

int main() {
    int n, s;
    scanf("%d%d", &n, &s);
    rep(i, n) rep(j, i+1) {
        a[i][j] = s++;
        if(s==10) s=1;
    }
    rep(j, n) rep(i, n) {
        if(i<j) printf("  ");
        else printf("%d%c", a[i][j], i<n-1 ? ' ' : '\n');
    }
    return 0;
}
