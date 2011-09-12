#include <stdio.h>
#include <string.h>

int ans, E, u[20000], v[20000], cost[20000], next[20000], head[10000];

int rec(int at, int pre) {
    int fst=0, snd=0;
    for(int x=head[at]; x!=-1; x=next[x]) if(v[x]!=pre) {
        int d=rec(v[x], at)+cost[x];
        if(fst<d) { snd=fst; fst=d; }
        else if(snd<d) snd=d;
    }
    if(ans<fst+snd) ans=fst+snd;
    return fst;
}

int main() {
    memset(head, -1, sizeof(head));
    int a, b, c;
    while(scanf("%d%d%d", &a, &b, &c)!=EOF) {
        a--, b--;
        u[E]=a; v[E]=b; cost[E]=c; next[E]=head[u[E]]; head[u[E]]=E; E++;
        u[E]=b; v[E]=a; cost[E]=c; next[E]=head[u[E]]; head[u[E]]=E; E++;
    }
    ans = -1;
    rec(0, -1);
    printf("%d\n", ans);
    return 0;
}
