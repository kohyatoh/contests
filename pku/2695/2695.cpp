#include <math.h>
#include <iostream>
#include <complex>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

typedef complex<double> P;
const double pi=atan2(0.0, -1.0);

int n, s;
double d, x[200], y[200];
P p[200];

double angle(const P& p, const P& q) {
    double a=fabs(arg(p)-arg(q));
    return a<pi ? a : 2*pi-a;
}

int main() {
    for(;;) {
        cin >> x[0] >> y[0] >> n >> s >> d;
        if(n==0) return 0;
        rep(i, n) cin >> x[i+1] >> y[i+1];
        rep(i, n+1) p[i] = P(x[i], y[i]);
        int cur=s, pre=-1;
        for(;;) {
            if(pre!=-1) cout << ' ';
            cout << cur;
            double ma=100;
            int mi=-1;
            rep(i, n) if(i+1!=cur) {
                if(pre>0 && angle(p[i+1]-p[cur], p[pre]-p[cur])<pi/2) continue;
                if(abs(p[i+1]-p[cur])>d) continue;
                double theta=angle(p[i+1]-p[cur], p[0]);
                if(theta>pi/2) continue;
                if(ma>theta) ma=theta, mi=i+1;
            }
            if(mi==-1) break;
            pre = cur;
            cur = mi;
        }
        cout << endl;
    }
}

