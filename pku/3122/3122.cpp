#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

const double pi = atan2(0.0, -1.0);

int n, f, r[10000];
double v[10000];

bool can(double x) {
    int s = 0;
    rep(i, n) s += (int)(v[i]/x);
    return s>=f+1;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &f);
        rep(i, n) scanf("%d", r+i);
        rep(i, n) v[i] = pi*r[i]*r[i];
        double l=0, r=*max_element(v, v+n);
        rep(_, 100) {
            double mid = (l+r)/2;
            if(can(mid)) l=mid;
            else r = mid;
        }
        printf("%.6f\n", l);
    }
    return 0;
}
