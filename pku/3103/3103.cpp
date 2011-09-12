#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    int x, y, z, n;
    scanf("%d%d%d%d", &x, &y, &z, &n);
    rep(i, n) {
        printf("%d %d %.9f %d %d %.9f\n",
                0, 0, (double)i*z/n,
                x, y, (double)(i+1)*z/n);
    }
    return 0;
}
