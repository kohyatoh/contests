#include <stdio.h>
#include <complex>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define EPS (1e-12)
typedef complex<double> P;
const double pi = atan2(0.0, -1.0);

P scanP() {
    double x, y;
    scanf("%lf%lf", &x, &y);
    return P(x, y);
}

double normalize(double t) {
    while(t<0) t += 2*pi;
    while(t>2*pi) t -= 2*pi;
    return t;
}

int solve(const vector<double>& as) {
    const int n = as.size();
    int j = 0, ans = 0;
    rep(i, n) {
        while(normalize(as[j]-as[i])<pi+EPS) {
            j = (j+1)%n;
            if(j==i) return n;
        }
        ans = max(ans, (j-i+n)%n);
    }
    return ans;
}

int main() {
    for(;;) {
        const P cp = scanP();
        double r;
        scanf("%lf", &r);
        if(r<0) return 0;
        int n;
        scanf("%d", &n);
        vector<double> as;
        while(n--) {
            const P p = scanP();
            if(abs(p-cp)<r+EPS) as.push_back(arg(p-cp));
        }
        sort(as.begin(), as.end());
        printf("%d\n", solve(as));
    }
}
