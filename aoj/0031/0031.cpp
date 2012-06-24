#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int g;
    while (scanf("%d", &g) != EOF) {
        int f = 0;
        rep (i, 10) if (g&(1<<i)) {
            if (f) printf(" ");
            f = 1;
            printf("%d", 1<<i);
        }
        printf("\n");
    }
    return 0;
}
