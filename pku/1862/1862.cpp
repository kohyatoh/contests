#include <stdio.h>
#include <math.h>
#include <algorithm>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, w[200];

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d", w+i);
    std::sort(w, w+n);
    double d=w[n-1];
    for(int i=n-2; i>=0; i--) d=2*sqrt(w[i]*d);
    printf("%.3f\n", d);
    return 0;
}
