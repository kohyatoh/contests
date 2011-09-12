#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int bitcount(int a) { int c=0; while(a) a&=a-1, c++; return c; }
int w, g[4][4];
char f[4][4];

bool check(int b) {
    rep(x, w) rep(y, w) if(f[x][y]=='X' && (b&(1<<(y*w+x)))) return false;
    rep(x, w) rep(y, w) g[x][y]=0;
    rep(x, w) rep(y, w) if(b&(1<<(y*w+x))) g[x][y]=1;
    rep(i, w) rep(j, w) if(g[i][j]) {
        for(int x=i+1; x<w && f[x][j]!='X'; x++) if(g[x][j]) return false;
        for(int y=j+1; y<w && f[i][y]!='X'; y++) if(g[i][y]) return false;
    }
    return true;
}

int main() {
    for(;;) {
        scanf("%d", &w);
        if(w==0) return 0;
        rep(i, w) rep(j, w) scanf(" %c", f[i]+j);
        const int ww=1<<(w*w);
        int ans=0;
        rep(b, ww) if(check(b)) ans=max(ans, bitcount(b));
        printf("%d\n", ans);
    }
}
