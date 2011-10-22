#include <stdio.h>
#include <stdlib.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int m, nxt[100000][10], f[100000];
char buf[32];

int add() {
    rep(i, 10) nxt[m][i] = -1;
    f[m] = 0;
    return m++;
}

int main() {
    gets(buf);
    int T = atoi(buf);
    while(T--) {
        gets(buf);
        int n = atoi(buf), ans = 1;
        m = 0;
        add();
        rep(i, n) {
            gets(buf);
            if(!ans) continue;
            int cur = 0;
            for(char *p=buf; *p; p++) {
                if(f[cur]==1) ans = 0;
                f[cur] = -1;
                if(nxt[cur][*p-'0']==-1) nxt[cur][*p-'0'] = add();
                cur = nxt[cur][*p-'0'];
            }
            if(f[cur]==-1) ans = 0;
            f[cur] = 1;
        }
        puts(ans ? "YES" : "NO");
    }
    return 0;
}

