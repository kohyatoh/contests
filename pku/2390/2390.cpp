#include <stdio.h>
#include <stdlib.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    int r, m, y;
    scanf("%d%d%d", &r, &m, &y);
    double c=m;
    rep(i, y) c*=(1+r/100.);
    char buf[80];
    sprintf(buf, "%.10f", c);
    printf("%d\n", atoi(buf));
    return 0;
}

