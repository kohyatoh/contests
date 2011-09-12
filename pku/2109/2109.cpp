#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double p;
    while(scanf("%d%lf", &n, &p)!=EOF) printf("%d\n", (int)(pow(p, 1.0/n)+0.5));
    return 0;
}

