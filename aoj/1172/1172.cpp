#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int pt[300000], sum[300000];

int main() {
    for(int i=2; i<300000; i++) if(pt[i]==0) {
        if(i<10000) for(int j=i*i; j<300000; j+=i) pt[j] = i;
    }
    rep(i, 280000) sum[i+1] = sum[i] + (pt[i]==0);
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        printf("%d\n", sum[2*n+1]-sum[n+1]);
    }
}
