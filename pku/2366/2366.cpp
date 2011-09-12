#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, a, x[90000];

int main() {
    scanf("%d", &n);
    rep(i, n) { scanf("%d", &a); x[a+40000]=1; }
    scanf("%d", &n);
    rep(i, n) {
        scanf("%d", &a);
        if(x[50000-a]) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}

