#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    scanf("%d", &n);
    int cur = 100000;
    rep (i, n) {
        cur += cur / 100 * 5;
        cur = (cur+999)/1000*1000;
    }
    printf("%d\n", cur);
    return 0;
}
