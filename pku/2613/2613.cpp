#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    int p, q, r, s;
    while(scanf("%d%d%d%d", &p, &q, &r, &s)!=EOF) {
        double ans=1.0;
        int m=q>s?q:s;
        for(int i=m-1; i>=0; i--) {
            if(i<q && i<s) ans=ans*(p-i)/(r-i);
            else if(i<q) ans=ans*(p-i)/(i+1);
            else if(i<s) ans=ans*(i+1)/(r-i);
        }
        printf("%.5f\n", ans);
    }
    return 0;
}

