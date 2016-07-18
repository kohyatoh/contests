#include <stdio.h>
#include <algorithm>
#include <complex>
#include <queue>
using namespace std;
typedef complex<double> P;
 
double cross(const P& a, const P& b) { return imag(conj(a)*b); }
double dot(const P& a, const P& b) { return real(conj(a)*b); }
int ccw(const P& a, P b, P c) {
    b-=a, c-=a;
    if (cross(b, c)>0) return 1;
    if (cross(b, c)<0) return -1;
//    if (dot(b, c)<0) return 2;
//    if (norm(b)<norm(c)) return -2;
    return 0;
}
 
int n, s, g, lx[300000], rx[300000];
deque<P> lps, rps;
deque<double> lds, rds;
 
int main() {
    scanf("%d%d%d", &n, &s, &g);
    for (int i = 0; i <= n; i++) scanf("%d%d", lx+i, rx+i);
    lx[n] = rx[n] = g;
    lps.push_back(P(s, 0));
    lds.push_back(0);
    rps.push_back(P(s, 0));
    rds.push_back(0);
    for (int i = 1; i <= n; i++) {
        P lp = P(lx[i], i);
        while (lps.size() >= 2
                && ccw(lps[lps.size() - 2], lps.back(), lp) < 0) {
            lps.pop_back();
            lds.pop_back();
        }
        lds.push_back(lds.back() + abs(lp - lps.back()));
        lps.push_back(lp);
 
        P rp = P(rx[i], i);
        while (rps.size() >= 2
                && ccw(rps[rps.size() - 2], rps.back(), rp) > 0) {
            rps.pop_back();
            rds.pop_back();
        }
        rds.push_back(rds.back() + abs(rp - rps.back()));
        rps.push_back(rp);
 
        if (lps.size() == 2) {
            while (ccw(rps[0], lps[1], rps[1]) > 0) {
                rps.pop_front();
                rds.pop_front();
            }
            lps[0] = rps[0];
            lds[0] = rds[0];
            lds[1] = lds[0] + abs(lp - lps[0]);
        } else if (rps.size() == 2) {
            while (ccw(lps[0], rps[1], lps[1]) < 0) {
                lps.pop_front();
                lds.pop_front();
            }
            rps[0] = lps[0];
            rds[0] = lds[0];
            rds[1] = rds[0] + abs(rp - rps[0]);
        }
    }
    printf("%.12f\n", min(lds.back(), rds.back()));
    return 0;
}
