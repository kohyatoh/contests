#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    double d, s=0;
    rep(i, 12) { scanf("%lf", &d); s+=d; }
    printf("$%.2f\n", s/12);
    return 0;
}
