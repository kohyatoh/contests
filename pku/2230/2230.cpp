#include <stdio.h>
#include <string.h>

int E, v[100000], rev[100000], next[100000], head[10000];
int n, m, used[100000];

void rec(int cur) {
    printf("%d\n", cur+1);
    for(int x=head[cur]; x!=-1; x=next[x]) if(used[x]==0) {
        used[x]=used[rev[x]]=1;
        rec(v[x]);
        printf("%d\n", cur+1);
    }
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    while(m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        v[E]=b; rev[E]=E+1; next[E]=head[a]; head[a]=E; E++;
        v[E]=a; rev[E]=E-1; next[E]=head[b]; head[b]=E; E++;
    }
    rec(0);
    return 0;
}
