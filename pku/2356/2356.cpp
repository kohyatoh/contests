#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int N, a[20000], s[20000], h[20000];

int main() {
    scanf("%d", &N);
    rep(i, N) scanf("%d", a+i);
    rep(i, N) s[i+1]=(s[i]+a[i])%N;
    rep(i, N) h[i]=-1;
    rep(k, N+1) {
        if(h[s[k]]==-1) h[s[k]]=k;
        else {
            printf("%d\n", k-h[s[k]]);
            for(int i=h[s[k]]; i<k; i++) printf("%d\n", a[i]);
            break;
        }
    }
    return 0;
}
