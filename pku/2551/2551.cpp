#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m, x[10000];

int main() {
    while(scanf("%d", &n)!=EOF) {
        m = 0;
        rep(i, 10000) x[i]=0;
        for(int k=0, fin=0; !fin; k++) {
            rep(t, 10) if((x[k]+n*t)%10==1) {
                int a=n*t, c=0;
                for(int i=k; a+c; i++) {
                    int b=(x[i]+a%10+c)%10;
                    c=(x[i]+a%10+c)/10;
                    a/=10;
                    x[i]=b;
                    if(x[i]!=0 && m<i+1) m=i+1;
                }
            }
            fin=1;
            for(int i=k+1; i<m; i++) if(x[i]!=1) { fin=0; break; }
        }
        printf("%d\n", m);
    }
    return 0;
}

