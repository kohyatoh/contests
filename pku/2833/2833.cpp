#include <stdio.h>
#include <limits.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    int n, n1, n2, x[16], y[16];
    for(;;) {
        scanf("%d%d%d", &n1, &n2, &n);
        if(n==0) return 0;
        rep(i, n1) x[i] = INT_MIN;
        rep(i, n2) y[i] = INT_MAX;
        double s = 0;
        rep(i, n) {
            int a;
            scanf("%d", &a);
            s += a;
            x[n1] = a;
            for(int i=n1-1; i>=0 && x[i]<x[i+1]; i--) swap(x[i], x[i+1]);
            y[n2] = a;
            for(int i=n2-1; i>=0 && y[i]>y[i+1]; i--) swap(y[i], y[i+1]);
        }
        rep(i, n1) s -= x[i];
        rep(i, n2) s -= y[i];
        printf("%.6f\n", s/(n-n1-n2));
    }
}
