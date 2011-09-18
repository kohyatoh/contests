#include <stdio.h>
#include <math.h>

int K, R, L;
double P, E, T;

inline bool inner(double t) { return fabs(t-T)<E; }

double calc(double r, double l, int k) {
    const double h = (r+l)/2;
    if(k==0) return inner(h) ? 1 : 0;
    if(inner(l) && inner(r)) return 1;
    else if(!inner(l) && !inner(r) && (l-T)*(r-T)>0) return 0;
    if(h<T) return calc(h, l, k-1)*(1-P)+calc(r, h, k-1)*P;
    else return calc(h, l, k-1)*P+calc(r, h, k-1)*(1-P);
}

int main() {
    scanf("%d%d%d%lf%lf%lf", &K, &R, &L, &P, &E, &T);
    printf("%.9f\n", calc(R, L, K));
    return 0;
}
