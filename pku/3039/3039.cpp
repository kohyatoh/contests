#include <stdio.h>
#include <math.h>

int gcd(int a, int b) { return b==0 ? a : gcd(b, a%b); }

int N, D, ansN, ansD;
double minv;

void update(int n, int d) {
    const int g = gcd(n, d);
    n /= g;
    d /= g;
    if(n==N && d==D) n--;
    if(n<=0) return;
    const double v = fabs((double)n/d-(double)N/D);
    if(minv > v) minv=v, ansN=n, ansD=d;
}

int main() {
    scanf("%d%d", &N, &D);
    ansN = ansD = 1;
    minv = 1e100;
    for(int i=1; i<=32767; i++) {
        update(N*i/D, i);
        update(N*i/D+1, i);
    }
    printf("%d %d\n", ansN, ansD);
    return 0;
}
