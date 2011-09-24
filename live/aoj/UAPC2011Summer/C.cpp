#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
typedef long long Int;

int n, m, p[30];

Int gcd(Int a, Int b) { return b==0 ? a : gcd(b, a%b); }

double solve() {
    sort(p, p+m);
    m = unique(p, p+m)-p;
    if(p[0]==1) return 0;
    Int sum = (1LL+n)*n/2, cnt=n;
    const int mm = 1<<m;
    rep(b, mm) if(b) {
        int sign = 1;
        Int a = 1;
        rep(i, m) if(b&(1<<i)) {
            sign = -sign;
            a = a*p[i]/gcd(a, p[i]);
            if(a>n) break;
        }
        if(a<=n) {
            const Int c = n/a;
            sum += sign*(a+c*a)*c/2;
            cnt += sign*c;
        }
    }
    return cnt ? (double)sum/cnt : 0;
}

int main() {
    for(;;) {
        scanf("%d%d", &n, &m);
        if(n==0 && m==0) return 0;
        rep(i, m) scanf("%d", p+i);
        printf("%.9f\n", solve());
    }
}


