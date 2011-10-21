#include <stdio.h>
#define INF (1LL<<60)
typedef long long Int;

int n, ta, tb, tc;
Int t;

void up(Int a, Int b, Int c) {
    Int s = (a*b+b*c+c*a)*2;
    if(t>s) t = s, ta = a, tb = b, tc = c;
}

void f(int a, int r) {
    for(int x=1; x<=a && x*x<=r; x++) if(r%x==0) up(a, x, r/x), up(a, r/x, x);
}

int main() {
    scanf("%d", &n);
    t = INF;
    for(int x=1; x*x<=n; x++) if(n%x==0) f(x, n/x), f(n/x, x);
    printf("%d %d %d\n", ta, tb, tc);
    return 0;
}
