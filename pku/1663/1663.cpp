#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    int n, x, y;
    scanf("%d", &n);
    rep(q, n) {
        scanf("%d%d", &x, &y);
        if(y==x || y==x-2) printf("%d\n", 4*(x/2)+x%2+y-x);
        else printf("No Number\n");
    }
    return 0;
}

