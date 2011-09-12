#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int pre[20000];

int cnt(int n, int a) {
    int c=0, p=a;
    while(p<=n) {
        c += n/p;
        p *= a;
    }
    return c;
}

int main() {
    pre[0] = 1;
    for(int i=1; i<20000; i++) {
        int k = i;
        while(k%2==0) k/=2;
        while(k%5==0) k/=5;
        pre[i] = pre[i-1]*k%10;
    }
    int n;
    while(scanf("%d", &n)!=EOF) {
        int t = pre[n];
        rep(i, cnt(n, 2)-cnt(n, 5)) t = (t*2)%10;
        printf("%5d -> %d\n", n, t);
    }
    return 0;
}
