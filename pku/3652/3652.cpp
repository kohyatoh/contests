#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int a, b, c, s;
int vis[65536];
char buf[32];

int main() {
    for(;;) {
        scanf("%d", &a);
        if(a==0) return 0;
        scanf("%d%d%d", &b, &c, &s);
        rep(i, 65536) vis[i]=0;
        int mask=0, x=s, nx;
        while(vis[x]==0) {
            vis[x]=1;
            nx=(a*x+b)%c;
            mask|=(x^nx);
            x=nx;
        }
        rep(i, 16) buf[15-i]=(mask&(1<<i))?'?':('0'+((s>>i)&1));
        puts(buf);
    }
}

