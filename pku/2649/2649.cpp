#include <stdio.h>

int calc(int n, int a) { int c=0; while(a<=n) c+=(n/=a); return c; }

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m)!=EOF) {
        bool yes=true;
        int t=m;
        for(int a=2; a*a<=t && a<60000; a++) if(t%a==0) {
            int c=0;
            while(t%a==0) c++, t/=a;
            if(c>calc(n, a)) { yes=false; break; }
        }
        if((m==0 && n>0) || (t>1 && n<t)) yes=false;
        printf("%d %s %d!\n", m, yes ? "divides" : "does not divide", n);
    }
    return 0;
}
