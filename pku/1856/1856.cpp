#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int N, M, minx, maxx, miny, maxy;
char f[1024][1024];

void rec(int x, int y) {
    if(f[x][y]!='#') return ;
    f[x][y] = '!';
    minx = min(minx, x); maxx = max(maxx, x);
    miny = min(miny, y); maxy = max(maxy, y);
    rec(x+1, y); rec(x-1, y);
    rec(x, y+1); rec(x, y-1);
}

bool check(int x0, int y0, int x1, int y1) {
    for(int y=y0-1; y<=y1+1; y++) {
        if(f[x0-1][y]!='.' || f[x1+1][y]!='.') return false;
    }
    for(int x=x0-1; x<=x1+1; x++) {
        if(f[x][y0-1]!='.' || f[x][y1+1]!='.') return false;
    }
    for(int x=x0; x<=x1; x++) for(int y=y0; y<=y1; y++) {
        if(f[x][y]!='!') return false;
    }
    return true;
}

int solve() {
    int ans = 0;
    rep(i, N) rep(j, M) if(f[i+1][j+1]=='#') {
        minx = N+1; maxx = 0;
        miny = M+1; maxy = 0;
        rec(i+1, j+1);
        if(!check(minx, miny, maxx, maxy)) return -1;
        ans++;
    }
    return ans;
}

int main() {
    for(;;) {
        gets(f[0]);
        sscanf(f[0], "%d%d", &N, &M);
        if(N==0 && M==0) return 0;
        rep(i, N) gets(f[i+1]+1);
        rep(i, N+2) f[i][0] = f[i][M+1] = '.';
        rep(i, M+2) f[0][i] = f[N+1][i] = '.';
        const int ans = solve();
        if(ans==-1) puts("Bad placement.");
        else printf("There are %d ships.\n", ans);
    }
}
