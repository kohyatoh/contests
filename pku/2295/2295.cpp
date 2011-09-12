#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

char s[1000];

int main() {
    int T=atoi(gets(s));
    while(T--) {
        gets(s);
        int x0=0, x1=0, f=1;
        char *p=s;
        while(*p) {
            if(*p=='=') f=-f, p++;
            else {
                int cf=f;
                if(*p=='-') cf=-cf, p++;
                else if(*p=='+') p++;
                int a=*p=='x'?1:atoi(p);
                while(isdigit(*p)) p++;
                if(*p!='x') x0+=a*cf;
                else x1+=a*cf, p++;
            }
        }
        if(x1==0) puts(x0 ? "IMPOSSIBLE" : "IDENTITY");
        else {
            int a=abs(x0), b=abs(x1);
            if(-x0*x1>=0) printf("%d\n", a/b);
            else printf("-%d\n", a/b+(a%b>0));
        }
    }
    return 0;
}
