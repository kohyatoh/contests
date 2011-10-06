#include <stdio.h>
#include <math.h>
#include <iostream>
#include <complex>
#include <vector>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define EPS (1e-9)
typedef complex<double> P;

const double g = 9.8;

int N, V, X, Y, L[60], B[60], R[60], T[60];
double f;

void calc_push(vector<P>& vs, double v, double x, double y) {
    if(x==0) return ;
    const double a = g*g/4, b = g*y-v*v, c = x*x+y*y;
    const double k[2] = {(-b+sqrt(b*b-4*a*c))/2/a, (-b-sqrt(b*b-4*a*c))/2/a};
    rep(i, 2) if(k[i]>0) {
        const double t = sqrt(k[i]);
        vs.push_back(P(x/t, y/t+g*t/2));
    }
}

double yof(double vy, double t) { return vy*t-g*t*t/2; }

bool can(double vx, double vy) {
    const double gy = yof(vy, X/vx);
    if(gy < Y-EPS || gy > f+EPS) return false;
    const double tt = vy/g, tx = vx*tt, ty = yof(vy, tt);
    rep(i, N) {
        double l = yof(vy, L[i]/vx), r = yof(vy, R[i]/vx);
        if(l>r) swap(l, r);
        if(B[i]+EPS<l && l<T[i]-EPS) return false;
        if(B[i]+EPS<r && r<T[i]-EPS) return false;
        if(l<B[i]-EPS && r>B[i]+EPS) return false;
        if(l<T[i]-EPS && r>T[i]+EPS) return false;
        if(l<B[i]-EPS && r<B[i]-EPS) {
            if(L[i]+EPS<tx && tx<R[i]-EPS && ty>B[i]+EPS) return false;
        }
        const double m = yof(vy, (L[i]+R[i])/2/vx);
        if(B[i]+EPS < m && m < T[i]-EPS) return false;
    }
    return true;
}

int main() {
    const double pi = atan2(0.0, -1.0);
    scanf("%d%d%d%d", &N, &V, &X, &Y);
    rep(i, N) scanf("%d%d%d%d", L+i, B+i, R+i, T+i);
    int k = 0;
    rep(i, N) if(L[i]<=X) {
        L[k] = L[i]; B[k] = B[i]; T[k] = T[i]; R[k] = min(R[i], X);
        k++;
    }
    N = k;
    f = 1e100;
    rep(i, N) if(L[i]<=X && X<=R[i] && T[i]>=Y) f = min(f, (double)B[i]);
    vector<P> vs;
    calc_push(vs, V, X, Y);
    rep(i, N) {
        calc_push(vs, V, L[i], T[i]);
        calc_push(vs, V, R[i], T[i]);
    }
    bool ans = false;
    rep(k, vs.size()) {
        if(can(real(vs[k]), imag(vs[k]))) ans = true;
    }
    puts(ans ? "Yes" : "No");
    return 0;
}
