#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    puts("n e");
    puts("- -----------");
    double cur = 1, f = 1;
    rep(i, 10) {
        printf("%d %.9f\n", i, cur);
        f *= (i+1);
        cur += 1.0/f;
    }
    return 0;
}
