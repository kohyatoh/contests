#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
char f[8][8];

inline bool inner(int x, int y) { return 0<=x && x<8 && 0<=y && y<8; }

int kount(int cx, int cy, char me, char ene) {
    if(f[cx][cy]!='.') return 0;
    int c = 0;
    rep(d, 8) {
        int x = cx+dx[d], y = cy+dy[d], t = 0;
        while(inner(x, y) && f[x][y]==ene) x+=dx[d], y+=dy[d], t++;
        if(inner(x, y) && f[x][y]==me) c += t;
    }
    return c;
}

void flip(int cx, int cy, char me, char ene) {
    if(f[cx][cy]!='.') return ;
    f[cx][cy] = me;
    rep(d, 8) {
        int x = cx+dx[d], y = cy+dy[d];
        while(inner(x, y) && f[x][y]==ene) x+=dx[d], y+=dy[d];
        if(inner(x, y) && f[x][y]==me) {
            int tx=cx, ty=cy;
            while(tx!=x || ty!=y) {
                f[tx][ty] = me;
                tx+=dx[d], ty+=dy[d];
            }
        }
    }
}

int main() {
    rep(i, 8) rep(j, 8) scanf(" %c", f[i]+j);
    int a, b;
    do {
        a = 0;
        rep(i, 8) rep(j, 8) a = max(a, kount(i, j, 'o', 'x'));
        if(a) rep(i, 8) rep(j, 8) if(kount(i, j, 'o', 'x')==a) {
            flip(i, j, 'o', 'x');
            a = -1;
        }
        b = 0;
        rep(i, 8) rep(j, 8) b = max(b, kount(i, j, 'x', 'o'));
        if(b) rep(i, 8) rep(j, 8) if(kount(7-i, 7-j, 'x', 'o')==b) {
            flip(7-i, 7-j, 'x', 'o');
            b = -1;
        }
    } while(a || b);
    rep(i, 8) {
        rep(j, 8) putchar(f[i][j]);
        putchar('\n');
    }
    return 0;
}
