#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, h[100000];

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d", h+i+1);
    h[0] = h[1];
    h[n+1] = h[n];
    for(int i=1; i<=n; i++) {
        if(h[i-1]<=h[i] && h[i]>=h[i+1]) printf("%d\n", i);
    }
    return 0;
}
