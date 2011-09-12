#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int u[50000], r[50000];
void unite(int x, int y) { u[y]=x; r[y]=abs(x-y)%1000; }
int root(int x) { return u[x]<0 ? x : u[x]=root(u[x]); }
int rank(int x) {
    if(u[x]>=0) {
        r[x]+=rank(u[x]);
        u[x]=root(u[x]);
    }
    return r[x];
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        memset(u, -1, sizeof(u));
        memset(r, 0, sizeof(r));
        int n;
        scanf("%d", &n);
        char ord;
        int x, y;
        for(;;) {
            scanf(" %c", &ord);
            if(ord=='O') break;
            else if(ord=='E') {
                scanf("%d", &x);
                printf("%d\n", rank(x));
            }
            else {
                scanf("%d%d", &x, &y);
                unite(y, x);
            }
        }
    }
    return 0;
}

