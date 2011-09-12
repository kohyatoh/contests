#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int F, N, M, W;
int E, from[6000], to[6000], cost[6000];
int d[600];

bool find_negative_loop() {
    rep(i, N) d[i]=0;
    rep(k, N) {
        rep(i, E) {
            if(d[to[i]]>d[from[i]]+cost[i]) {
                d[to[i]]=d[from[i]]+cost[i];
                if(k==N-1) return true;
            }
        }
    }
    return false;
}

int main() {
    scanf("%d", &F);
    rep(q, F) {
        scanf("%d%d%d", &N, &M, &W);
        E = 0;
        rep(i, M) {
            int s, e, t;
            scanf("%d%d%d", &s, &e, &t);
            s--; e--;
            from[E]=s; to[E]=e; cost[E]=t; E++;
            from[E]=e; to[E]=s; cost[E]=t; E++;
        }
        rep(i, W) {
            int s, e, t;
            scanf("%d%d%d", &s, &e, &t);
            s--; e--;
            from[E]=s; to[E]=e; cost[E]=-t; E++;
        }
        puts(find_negative_loop() ? "YES" : "NO");
    }
    return 0;
}

