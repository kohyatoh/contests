#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int pre[100000], nxt[100000], is[100000];

int main() {
    int N, K, P;
    scanf("%d%d%d", &N, &K, &P);
    rep(i, K) nxt[i] = i+1;
    nxt[K-1] = 0;
    rep(i, K) pre[i] = i-1;
    pre[0] = K-1;
    const int M = K/N;
    int cur = 0;
    rep(_, M) rep(i, N) {
        is[cur] = i==N-1;
        nxt[pre[cur]] = nxt[cur];
        pre[nxt[cur]] = pre[cur];
        rep(__, P+1) cur = nxt[cur];
    }
    rep(i, K) if(is[i]) printf("%d\n", i+1);
    return 0;
}
