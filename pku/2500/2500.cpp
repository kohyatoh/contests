#include <stdio.h>
#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;
typedef complex<double> P;
double PI = atan2(0, -1);
double cross(const P& p, const P& q) { return imag(conj(p)*q); }

int d, n, c, g;
int pc[1000];
P ps[1000];

double max_tri(int b, int i, int u) {
    double mx = 0.0;
    while(i<u) { mx = max(mx, abs(cross(ps[b]-ps[0], ps[i]-ps[0]))/2); i++; }
    return mx;
}

int main() {
    int S;
    scanf("%d", &S);
    rep(q, S) {
        scanf("%d%d%d%d", &d, &n, &c, &g);
        rep(i, c) pc[i] = (g*(long long)i)%n;
        sort(pc, pc+c);
        rep(i, c) ps[i] = d*0.5*P(cos(2*PI*pc[i]/n), sin(2*PI*pc[i]/n));
        double ans = 0.0;
        for(int i=2; i<c-1; i++) {
            ans = max(ans, max_tri(i, 1, i)+max_tri(i, i+1, c));
        }
        printf("Scenario #%d:\n", q+1);
        printf("%.6f\n\n", ans);
    }
}
