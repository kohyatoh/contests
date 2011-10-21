#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m, u[16][16];
char f[16][16];

void visit(int x, int y) {
    u[x][y] = 1;
    if(f[x][y]=='-') {
        if(y<m-1 && f[x][y+1]=='-') visit(x, y+1);
    }
    if(f[x][y]=='|') {
        if(x<n-1 && f[x+1][y]=='|') visit(x+1, y);
    }
    if(f[x][y]=='/') {
        if(x<n-1 && y>0 && f[x+1][y-1]=='/') visit(x+1, y-1);
    }
    if(f[x][y]=='\\') {
        if(x<n-1 && y<m-1 && f[x+1][y+1]=='\\') visit(x+1, y+1);
    }
}

bool solve() {
    memset(u, 0, sizeof(u));
    int c = 0;
    rep(i, n) rep(j, m) if(u[i][j]==0 && f[i][j]!='.') {
        c++;
        if(c>1) return false;
        visit(i, j);
    }
    return c==1;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        rep(i, n) rep(j, m) scanf(" %c", f[i]+j);
        puts(solve() ? "CORRECT" : "INCORRECT");
    }
    return 0;
}
