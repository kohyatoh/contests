#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    while(K--) {
        int s, t, r;
        scanf("%d%d%d", &s, &t, &r);
        const int p = s*t;
        printf("%d\n", N/p*t+(N%p+s-1)/s+(N-1)/p*r);
    }
    return 0;
}
