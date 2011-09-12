#include <stdio.h>

int extgcd(int a, int b, int& x, int& y) {
    int g=a; x=1, y=0;
    if(b!=0) { g=extgcd(b, a%b, y, x); y-=(a/b)*x; }
    return g;
}

int f(int a, int b, int p, int q) {
    int x, y, z=a-b;
    extgcd(p, q, x, y);
    while(y<0) y+=p;
    while(z<0) z+=p;
    y = y*z%p;
    return b+q*y;
}

int main() {
    const int P=23, Q=28, R=33;
    const int pr = P*Q*R;
    int p, e, i, d;
    for(int q=0;; q++) {
        scanf("%d%d%d%d", &p, &e, &i, &d);
        if(p==-1) return 0;
        p%=P, e%=Q, i%=R;
        int x = f(p, e, P, Q);
        int y = f(x, i, P*Q, R);
        int z = d>=y ? y+pr+(d-y)/pr*pr : y-(y-d-1)/pr*pr;
        printf("Case %d: the next triple peak occurs in %d days.\n", q+1, z-d);
    }
}
