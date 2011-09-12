#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int d[1000];
int N, T, E, fr[5000], to[5000], cost[5000];
#define INF (1<<28)

int main() {
    scanf("%d%d", &T, &N);
    rep(i, T) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        fr[E]=a-1; to[E]=b-1; cost[E]=c; E++;
        fr[E]=b-1; to[E]=a-1; cost[E]=c; E++;
    }
    rep(i, N) d[i]=INF;
    d[0] = 0;
    rep(k, N-1) {
        bool updated=false;
        rep(i, E) {
            if(d[to[i]]>d[fr[i]]+cost[i]) {
                d[to[i]]=d[fr[i]]+cost[i];
                updated=true;
            }
        }
        if(!updated) break;
    }
    printf("%d\n", d[N-1]);
    return 0;
}
