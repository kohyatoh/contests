#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    rep (i, 9) rep (j, 9) {
        printf("%dx%d=%d\n", i+1, j+1, (i+1)*(j+1));
    }
    return 0;
}
